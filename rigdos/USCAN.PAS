(* changes:
   11-nov-92
    Now in m+ mode "AB""CD" is accespted as AB"CD value
    Earlier it were two values "AB" and "CD"
*)
{$DEFINE MIF}

{$DEFINE RAMSCAN}
{$DEFINE SCANU}
{   Rigal integrated environment (c) 1991 Software house Riga }
{                                                             }
{                                                             }
{$IFDEF SCANU}
Unit Scan;
interface
uses
{$IFDEF WIN} tmemstrm,winprocs, {$ENDIF}
define;
{ Separate scanner for input strings and output Rigal objects }
Procedure INITIALIZE_SCAN_VARIABLES;
Procedure Scaner
{*****************************************}
                 (mode_parm:integer;
     {1=from file,2=list of strings,3=absulute address,
      4=stream memory handle }
                 filename:string80;
                 options_str:string80;
                 var rez:a; { result; set to NULL if input is absent }
                 var erlist_parm:a; { error number list; set to NULL if no errors }
                 strlist:a; { list of atoms }
                 segm,ofs:longint); { parts of absolute address }



implementation
uses defpage,nef,poutlexu,doutu;
{$ELSE}
#include "define.p"
#include "defpage.inc"
#include "nef2.inc"
#include "outs.inc"
#include "scan.inc"
{$ENDIF}


{VARIABLES}
type bigstring=
{$IFDEF xSUN}
 varying array[127] of char;
{$ELSE}
     string [127];
{$ENDIF}
var a1: a; { global variable for ONLY LOCAL use }
    {aa1 : aa ;} { --"-- }
     X : MPD; { --"-- }
     bl801 : bl80; { -- " -- }{ array[1..80] of char}
     k,kk:integer; { -"- }
     c1:char;

     saved_coord, { where current token began }
     coord_mark , { what was set by coordinate marker }
     line_byte_number , { number of totally read bytes till beginning
                           of current line }
     last_mark_byte_number , { number of totally read bytes till
                            last coordinate marker }
     old_line_length { length of the current line,
                        used only for incrementation of "lyne_byte_number"}
      :word;
     DT:descriptortype; { type of last read token or control character }
     AADR:a;          { A-space address of last read token }
     Linenumber:longint; { Current line number }
     Tokennumber:longint;{ Current token number }
     Errlist :a;      { List of numbers of errors }
     Read_mode:integer;  { 1,2,3 }
     PTR1     : PTR;  { List pointer when read from list of atoms }
{$IFDEF RAMSCAN}
     ABSPNT   : Pointer;{ RAM pointer when read from RAM }
{$ENDIF}
     inpfile  : text;
var
    c_lexics,
    pascal_lexics,
    row80_coord,
    byte_coord,
    mark_byte_coord,
    mark_only_coord,
    string_coord,
    char_coord,
    token_coord,
    collect_errors,
    screen_errors,
    to_uppercase,
    pascal_comment,
    c_comment,
    ada_comment,
    pascal_string,
    modula_string:boolean;

const new_line_code=Chr(13); { Chr(0 is allowed too }
      endfile_code =Chr(26);
var   s:bigstring;
      s_for_val:bigstring; { added 17-FEB-92 }
      i:integer;

type is_something=
  (is_control,  is_letter, is_digit, is_underscore, is_printable,
   is_special,  is_space , is_first_of_two);

type pair=packed array[1..2]of char;
var as:array[char]of is_something;
    isa : is_something;
    upcase_tab:array[char]of char;
    set_of_second_of_two:set of char;
    two_char_symbols_num:integer;
    two_char_symbols:array[1..30]of pair;

    b123 : record
           case integer of
           1:(b1:char);
           2:(b2:packed array[1..2]of char);
           3:(b3:packed array[1..3]of char);
           end;


var in_comment,in_string : boolean;
var is_2quote : boolean; { if in_string then it is possible }
var Str_constlen:longint;
    Str_const : string80; { array of char is allowed too }

{=====  SUN VERSION ===}
{$IFDEF SUN}
procedure inc{1}(var xxx:longint);
 begin  xxx:=xxx+1; end;
procedure inc{2}(var xxx:longint;yyy:longint);
 begin  xxx:=xxx+yyy; end;
procedure inc{3}(var xxx:integer);
 begin  xxx:=xxx+1; end;
procedure inc{4}(var xxx:integer;yyy:integer);
 begin  xxx:=xxx+yyy; end;
{$ENDIF}
{=====}

function  CONT_CHAR_TO_DT(c:char):descriptortype;forward;
function  Getcoord:word;forward;
procedure ER_LEX(er_number:integer);forward;
{Procedure INITIALIZE_SCAN_VARIABLES;forward;}
Procedure READ_FILE(var read_file_rez:a);forward;
Function  READ_ITEM(var pghead:a):a;forward; {NEW!}
Procedure READLINE;forward;
Procedure PutAtom(j:integer);forward;
Procedure PutIt(dd:descriptortype;j:integer);forward;
Procedure PutIdent(j:integer);forward;
Procedure PutFloat(j:integer;digits_before_dot,digits_after_dot:integer);forward;
Procedure PutNumber;forward;
Procedure PutStr;forward;
Procedure PutStr2;forward;
{Procedure Scaner;forward;}
Procedure SETLEXICS;forward;
Procedure StrAdd(c:char);forward;
Procedure StrBegin;forward;
Procedure Token;forward;
Function TAKE_DIGITS(var jj:integer):longint;forward;
Function TAKE_LETTERS:integer;forward;



{ uses global string, received from Readline procedure,
  produces global attributes of new one token read.
  Some variables also should be initialized if by Initial_token
  procedure at the start of the WHOLE programm }

{ This procedure is oriented to Turbo Pascal language }
{ Procedure call graph follows :
                                  /self\
  USEPAS -> SCAN -> READFILE -> READITEM  ->  ADDEL.nef
                             -> LCONC.nef     ER_LEX
                 -> SETOPTIONS                GETS1.defpage
                 -> FIRST.nef                 TOKEN
                 -> ASSIGN.system             POINTR.defpage
                 -> RESET.system              LCONC.nef
                 -> READLINE


  TOKEN    -> ER
                -> READ_LETTERS_OR_DIGITS
                -> READ_DIGITS
                -> STRBEGIN
                -> PUTNUMBER
                -> StrAdd -> ER
                -> PUTSTR -> PUTATM.defpage
                -> PutAtom ->\
                -> PUTFLOAT     -> PUTIT -> PUTATM.defpage
                -> PUTIDENT     ->/
}



function CONT_CHAR_TO_DT(c:char):descriptortype;
{**********************************************}
begin
 Cont_char_to_dt:=descriptortype(c);
 {$IFDEF MIF}
   if c='<' then cont_char_to_dt:=start_list;
   if c='>' then cont_char_to_dt:=end_list;
 {$ENDIF}
end;


function  Getcoord:word;
{***********************}
begin
 if row80_coord then         Getcoord:=i+Linenumber*80
 else
 if mark_only_coord then     Getcoord:=coord_mark
 else
 if mark_byte_coord then
                             Getcoord:=coord_mark+
                             (line_byte_number+i-last_mark_byte_number)
 else
 if byte_coord then          Getcoord:=line_byte_number+i
 else
 if string_coord then        Getcoord:=Linenumber
 else
 if token_coord then         Getcoord:=Tokennumber
 else
  Getcoord:=0;
end;


procedure ER_LEX(er_number:integer);
{***********************************}
  var er_atom:a;co:word;erm:string80;
  begin
  co:=Getcoord;
  if collect_errors then begin
      Gets1(er_atom,x.sa);
      with  x.snd^ do begin
         dtype:=number;
         cord:=co;
         val:=er_number;
      end;
      lconc(errlist {global} ,er_atom);
    end;
  if screen_errors then
     begin
     case er_number of
     1 : erm:=' unexpected end of file before end of tree';
     2 : erm:=' unexpected end of file within tree branch ';
     3 : erm:=' unexpected end of file within tree        ';
     4 : erm:=' unexpected end of file before end of list ';
     5 : erm:=' unexpected end of tree                    ';
     6 : erm:=' unexpected end of list or another control character';
     7 : erm:=' unexpected end of file in name            ';
     8 : erm:=' unexpected end of file in named object    ';
     9 : erm:=' unexpected control character             ';
     10 : erm:=' too long atom ( more than 80 bytes )    ';
     11 : erm:=' end of string constant not found in the current line';
     12 : erm:=' end of file before end of comment';
     13 : erm:=' control character within comment ';
     14 : erm:=' control character within string constant';
     end;
     writeln('Lexical error :',erm);
     writeln('Line=',linenumber,' column=',i);
     end;
end;




Procedure INITIALIZE_SCAN_VARIABLES;
{***********************************}
var c:char;
begin
  for c:=Chr(0) to Chr(255) do upcase_tab[c]:=c;
  for c:=Chr(97) to Chr(122) do upcase_tab[c]:=Chr(ord(c)-32);{ASCII}
(*  for c:=Chr(160) to Chr(175) do upcase_tab[c]:=Chr(ord(c)-32); *){Russian}
(*  for c:=Chr(224) to Chr(239) do upcase_tab[c]:=Chr(ord(c)-60);*){Russian}

 { German for Windows }
  upcase_tab[chr(228)]:=chr(196);
  upcase_tab[chr(246)]:=chr(214);
  upcase_tab[chr(252)]:=chr(220);

  for c:=Chr(0) to Chr(31) do as[c]:=is_control;
  for c:=Chr(128) to Chr(255) do as[c]:=is_letter; { Russian and pseudographics }
  for c:=Chr(32) to Chr(127) do as[c]:=is_printable; { not used actually }
  as[new_line_code]:=is_control;

  as[' ']:=is_space;
  as[Chr(9)] :=is_space;
    { these are allowed to be First letter of identifiers }
  for c:='A'to'Z' do as[c]:=is_letter;
  for c:='a'to'z' do as[c]:=is_letter;
  for c:='0'to'9' do as[c]:=is_digit;
    { allowed to be non-first letter of odentifier }
  as['_']:=is_underscore;

{ All the rest settings - see procedure SETLEXICS }

end;








Procedure READ_FILE(var read_file_rez:a);
{******************************}
 { reads whole input, produces list of items }
 label 99;
 var dum:a;
 begin read_file_rez:=NULL;
    repeat a1:=read_item(dum);
           if (dt=start_tree)or(dt=end_tree)or(dt=start_list)or
              (dt=end_list)or(dt=name_obj) then begin ER_LEX(6);goto 99;end;
           if DT<>eof_desk then lconc(read_file_rez,a1);
    until DT=eof_desk;
99: end;



Function READ_ITEM(var pghead:a):a;
{********************}
  label 99;
  var aadr1:a; result,temp_res,dum,head:a;
  begin
   READ_ITEM:=NULL; { default value for exits with errors }
   pghead:=NULL;
   result:=NULL;
   TOKEN;
   case DT of
    atom,idatom,tatom,fatom,keyword:
      begin gets1(result,x.sa);
            with x.sad^ do begin
               dtype:=DT;  cord:=saved_coord;
               name := AADR;
            end
      end;
   number:
     begin gets1(result,x.sa);
           with x.snd^ do begin
                dtype:=DT; cord:=saved_coord;
                val:= AADR; { is set in TOKEN .. is_digit }
           end;
     end;
  start_tree:
     begin result:=NULL;
        repeat
          TOKEN;
          aadr1:=AADR; { to save }
          if (DT=idatom)or(DT=atom)or(DT=tatom)or(DT=keyword)
            { What is allowed selector in scaner input ?
              Normally - idatom only, but here
              atom is allowed too - for experiment purposes }
            then
             begin
             a1:=Read_item(dum);
             if DT=end_list then begin ER_LEX(6); goto 99; end;
             if DT=eof_desk then begin ER_LEX(1);goto 99;end;
             Addel3(result,aadr1,a1);
             end
          else if DT<>end_tree then begin ER_LEX(2);goto 99;end;
          ;
        until (DT=end_tree)or(DT=eof_desk);
        if DT=eof_desk then begin ER_LEX(3);goto 99;end;
        DT:=complex_desk; { to ignore analysis in upper level of
                            recursion }
      end;
    start_list :
      begin
        result:=NULL;
   {$IFDEF MIF}
        pghead:=READ_ITEM(dum);
        repeat
           a1:=read_item(head);
           if DT=eof_desk then begin ER_LEX(4);goto 99;end;
           if (DT<>end_list) then
              begin
              if head<>NULL then lconc(result,head);
              lconc(result,a1);
              end;
        until DT=end_list;

   {$ELSE}
        repeat
           a1:=read_item;
           if DT=eof_desk then begin ER_LEX(4);goto 99;end;
           if (DT<>end_list) then lconc(result,a1);
        until DT=end_list;

   {$ENDIF}
        DT:=complex_desk;

      end;
   end_tree : begin ER_LEX(5);  goto 99; end;
   end_list : begin end; {immodiately returns to the upper level}
   name_obj: begin
      temp_res:=read_item(dum);
      if DT=end_list then begin ER_LEX(6); goto 99; end;
      if DT=eof_desk then begin ER_LEX(7); goto 99; end;
      result :=read_item(dum);
      if DT=end_list then begin ER_LEX(6); goto 99; end;
      if DT=eof_desk then begin ER_LEX(8); goto 99; end;
      if result<>NULL then begin
         points(result,x.sa);
         if (x.smld^.dtype=listmain)or(x.smtd^.dtype=treemain)
            then x.smtd^.name:=temp_res;
        end;
      DT:=complex_desk;
      end;
    eof_desk:begin end; { returns to the upper level }
{$IFDEF xSUN}
           OTHERWISE
{$ELSE}
           ELSE
{$ENDIF}

      begin ER_LEX(9);goto 99; end { impossible value }
    end; { case }
  read_item:=result;
99:  end; { Procedure Read_item }




Procedure READLINE;
{***************************}
{ sets new values for "s" and "i" global variables }
label 99;
begin
i:=1; { In any case, so; only here it is initialized.
        it is column number.
        Variable "s" is string only for speed purposes;
        It plays exactly as Packed array of char,
        never used as whole and the Length byte is never used }
Linenumber:=linenumber+1;
line_byte_number:=line_byte_number+old_line_length;

case read_mode of
1:
 begin
  if eof(inpfile) then begin s[1]:=endfile_code;close(inpfile);end
  else
  begin readln(inpfile,s);s[length(s)+1]:=new_line_code;
        old_line_length:=length(s);
  end;
 end;
2:
  begin
    if PTR1.nel=0 then begin s[1]:=endfile_code;goto 99;end;
    if PTR1.cel=0
       then begin
            s[1]:=new_line_code;
            old_line_length:=0;
            end
       else begin
            Pointr(PTR1.cel,X.sa);
            with x.sad^ do begin
            if (dtype=atom)or (dtype=idatom)or
              (dtype=fatom)or (dtype=tatom)or (dtype=keyword)
            then begin
              pointa(name,bl801,k);
              for kk:=1 to k do s[kk]:=bl801[kk];
              old_line_length:=k;
              s[k+1]:=new_line_code;
              end
            else
              begin
              s[1]:=new_line_code; { other objects are ignored }
              old_line_length:=0;
              end
         end; { with }
      end; { <>0 }
   NEXT(PTR1);
   end; {=2}
3:
    begin
{$IFDEF RAMSCAN}
     k:=0;
     repeat c1:=char(Pointer(ABSPNT)^);
            write(':',ord(c1));
            inc{1}(longint(ABSPNT));
            inc{1}(k);
            s[k]:=c1;
     until (c1=new_line_code)or(k=126);
     if (k=126) then
        begin
        writeln('SCANNER DIRECT ACCESS WARNING !');
        s[127]:=new_line_code;
        end;
     old_line_length:=k;
{$ENDIF}
     end;
4:   begin
 {$IFDEF WIN}
 (* reads by-byte from global memory stream *)
 s:='';
 k:=0;
 while true do begin
  byte(c1):=SM^.readbyte;
  if c1=#13 then begin (* eoln symbol reached *)
        old_line_length:=k;
        (* this variable must refer to last symbol before eoln *)
        s[k+1]:=new_line_code;Exit;end;
  if c1=#26 then begin (* end of file reached *)
        old_line_length:=k;
        inc(k);
        s[k]:=endfile_code;
        SM^.Close;Dispose(SM,Done);Exit;end;
  if c1<>#10 then
     begin
     Inc(k);s[k]:=c1;inc(byte(s[0])); (* adds one character to string *)
     end;
 end;
 {$ENDIF}
     end;
end; (* case *)
99:;
end;





Procedure PutAtom(j:integer);
{***********************}
  begin
  PutIt(atom,j);
  end;

Procedure PutIt(dd:descriptortype;j:integer);
{***********************}
  begin
  if j>80 then begin  DT:=Keyword;ER_LEX(10);j:=80; end else DT:=dd;
  putatm(s[i],j,AADR);
  saved_coord:=Getcoord;
  Tokennumber:=Tokennumber+1;
  end;

Procedure PutIdent(j:integer);
{***********************}
  begin
  PutIt(idatom,j);
  end;


Procedure PutFloat(j:integer;digits_before_dot,digits_after_dot:integer);
{***********************}
var REA_VAL:real; ii:integer;
    AR:array[1..sizeof(real)+2]of char;
  begin

(*  Val2(Copy(s,i,j),REA_VAL,ii ignored ); *)
  system.Val(Copy(s,i,j),REA_VAL,ii);
  if ii<>0 then
    begin
    if j>80 then j:=80;
    DT:=keyword;  (* WRONG REAL CONSTANT *)
    putatm(s[i],j,aadr);
    end
  else
    begin
    ii:=sizeof(real)+2;
    for j:=1 to ii-2 do
      AR[j]:=REAL_CHAR(REA_VAL)[j];
    AR[ii-1]:=chr(digits_before_dot);
    AR[ii]  :=chr(digits_after_dot);
    putatm(AR[1],ii,AADR);
    DT:=fatom;
    end;

(* writeln(' BEF, AFT =',digits_before_dot,' ',digits_after_dot); *)
  saved_coord:=Getcoord;
  inc{1}(Tokennumber);
  end;


Procedure PutNumber;
{***********************}
  begin
  DT:=number;
  saved_coord:=Getcoord;
  inc{1}(Tokennumber);
  end;

Procedure PutStr;
{***********************}
  begin
  if str_constlen>80 then
   begin
   str_constlen:=80;
   DT:=keyword; (* TOO LONG STRING CONSTANT *)
   end
  else
  DT:=TATOM;
  putatm(Str_const[1],Str_constlen, AADR);
  in_string:=false;
  Tokennumber:=Tokennumber+1;
  end;

Procedure PutStr2;
{***********************}
  begin
  if str_constlen>80 then str_constlen:=80;
  putatm(Str_const[1],Str_constlen, AADR);
  DT:=keyword;
  in_string:=false;
  Tokennumber:=Tokennumber+1;
  end;
 { this procedure used only for Modula2 or C-style string constants like 'x', -
   to show difference between 'x' and "x".
   Access via #_KEYWORD built_in rule is possible.
   When input  use 'm+p-' !
   When output such tokens you should write
    IF #_KEYWORD($X) -> OUT <] @ '"' $X '"' ELSIF T-> OUT <] $X FI;
  }




Procedure Scaner
{*****************************************}
                 (mode_parm:integer;
     {1=from file,2=list of strings,3=absulute address}
                 filename:string80;
                 options_str:string80;
                 var rez:a; { result; set to NULL if input is absent }
                 var erlist_parm:a; { error number list; set to NULL if no errors }
                 strlist:a; { list of atoms }
                 segm,ofs:longint); { parts of absolute address }

LABEL 1,99;

 {INNER FUNCTION}
  Function Setop(c:char):boolean;
   begin
    Setop:=false;
{$IFDEF xSUN}
    k:=Index(options_str,c);
{$ELSE}
    k:=Pos(c,options_str);
{$ENDIF}
    if k<>0 then
     if options_str[k+1]<>'-' then Setop:=true;
   end;

 begin

 read_mode:=mode_parm ; { save for global use }
 rez:=NULL;
 erlist_parm:=NULL;
 ERRLIST { global }:=NULL;

{ INITIALIZES  ALL  OPTIONS }
  { DEFAULTS }
  options_str:=options_str+'D-C-P+p+m-U+S+O+s-t-L-A+R+Y-B-N-';
  { to every option su,me default value should be given,
    otherwise the flag remains uninitialized }

{ERRORS}
  screen_errors :=Setop('S');
  collect_errors:=Setop('O');

{COMMENTS}
  ada_comment   :=Setop('D');
  c_comment     :=Setop('C');
  pascal_comment:=Setop('P');

{STRING CONSTANTS}
  pascal_string :=Setop('p');
  modula_string :=Setop('m');
  to_uppercase  :=Setop('U');

{COORDINATE}
  string_coord  :=Setop('s');
  token_coord   :=Setop('t');
  row80_coord   :=Setop('R');
  byte_coord    :=Setop('Y');
  mark_byte_coord:=Setop('B');
  mark_only_coord:=Setop('N');

{LANGUAGE_SPECIFIC LEXICS}
  c_lexics      :=Setop('L');
  pascal_lexics :=Setop('A');


 { INITIALIZES LANGUAGE-SPECIFIC SETTINGS }
  SETLEXICS;

 { INITIALIZES "SESSION" FLAGS (alf order)}
 coord_mark:=0;
 in_comment:=false;
 in_string :=false;
 is_2quote :=false;
 last_mark_byte_number:=0;
 line_byte_number:=0;
 linenumber:=0;
 old_line_length :=0;
 str_constlen:=0;
 tokennumber:=0;

 { INITIALIZES PHYSICAL LEVEL READING }
 case read_mode of
1:  begin  { READ FROM FILE }
   if not existfile(filename)then begin Rez:=0;goto 1;end;

    {$IFDEF xSUN}
    Reset(inpfile,filename);
    {$ELSE}
    Assign(inpfile,filename);
    Reset(inpfile);
    {$ENDIF}

    readline;   { reads first line of file }
    end;
2:
    begin { READ FROM LIST }
     if strlist=NULL then begin Rez:=0; goto 99; end;
     First(strlist,PTR1); { sets global list-pointer PTR1 }
     if (PTR1.ptrtype<>ptrlist) or
        (PTR1.nel=0) then begin Rez:=0; goto 99; end;
     readline;  { reads line from current list-pointer position }
     end;
3:
     begin { READ FROM MS-DOS RAM MEMORY }
     {$IFDEF RAMSCAN}
     { Normalizing memory address }
     { Is it necessary for Windows model ? }
  {   segm:=segm+ofs div 16;
      ofs:=ofs mod 16; }
     ABSPNT:=system.Ptr(segm,ofs); { This place is DOS-dependent !!! }
     if char (ABSPNT^) <> new_line_code
        then begin Rez:=0; goto 99; end;
     ABSPNT:=Pointer(longint(ABSPNT)+1);
     readline;
    {$ENDIF}
     end;
4:   begin
     {$IFDEF WIN}
     New(SM,Init);
     SM^.open(segm);
     if (SM^.GETSIZE>128000)or(SM^.GETSIZE<0) THEN
       begin
       MESSAGEBOX(0,'Wrong handle to LDT stream',nil,16);
       rez:=0; goto 99; end
     else if (SM^.GETSIZE=0) then
       begin
       MESSAGEBOX(0,'Empty LDT stream',nil,16);
       rez:=0; goto 99; end
     else
       begin
       readline;
       end;
     {$ENDIF}
     end;

end; (* case *)


 READ_FILE(REZ); { Main call ... }

 erlist_parm:=ERRLIST {global} ;
1:;99:;
end;{ procedure Scaner }


Procedure SETLEXICS;
{***********************}
var j:integer;
begin
{$IFDEF MIF}
  as['<']:=is_control;
  as['>']:=is_control;
  Exit;
{$ENDIF}


 if pascal_lexics then begin { changes in standard, necessary for Pascal}
  as['{']:=is_special;
  as['#']:=is_special;
  as['$']:=is_special;
  as['%']:=is_special;
  as['''']:=is_special;
  as['(']:=is_special;
  two_char_symbols[1]:=':=';
  two_char_symbols[2]:='<=';
  two_char_symbols[3]:='>=';
  two_char_symbols[4]:='**';
  two_char_symbols[5]:='..';
  two_char_symbols[6]:='<>';
  two_char_symbols_num:=6;
  set_of_second_of_two:=['=','*','.','>'];
  for j:=1 to two_char_symbols_num do
     as[two_char_symbols[j][1]]:=is_first_of_two;
  if modula_string then
       begin
       as['"']:=is_special;
       as['{']:=is_printable;
       end
end
else
if c_lexics then begin
  as['_']:=is_letter;
  as['$']:=is_letter;
  two_char_symbols[1]:='->';
  two_char_symbols[2]:='++';
  two_char_symbols[3]:='--';
  two_char_symbols[4]:='>>';
  two_char_symbols[5]:='<<';
  two_char_symbols[6]:='==';
  two_char_symbols[7]:='+=';
  two_char_symbols[8]:='*=';
  two_char_symbols[9]:='-=';
  two_char_symbols[10]:='/=';
  two_char_symbols[11]:='%=';
  two_char_symbols[12]:='&=';
  two_char_symbols[13]:='^=';
  two_char_symbols[14]:='|=';
  two_char_symbols[15]:='!=';
  two_char_symbols_num:=15;
  set_of_second_of_two:=['>','+','-','<','='];
  for j:=1 to two_char_symbols_num do
     as[two_char_symbols[j][1]]:=is_first_of_two;
  as['<']:=is_special; { used to process <<= }
  as['>']:=is_special; { used to process >>= }
  as['/']:=is_special; { used to process /*  }
                       { otherwise isa:=is_first_of_two
                         is assigned ! }
  as['''']:=is_special;
  as['"']:=is_special;

 end;
end;




Procedure StrAdd(c:char);
{***********************}
 begin
   inc{1}(Str_constlen);
   if Str_constlen<=80 then  Str_const[Str_constlen]:=c;
 end;

Procedure StrBegin;
{******************}
  begin
  saved_coord:=GetCoord;
 { It will be used when PutStr works and TOKEN EXITs - in READ_ITEM}
  in_string:=true;
  Str_constlen:=0;
  end;





Procedure Token;
{********************}
label 1,99;
var J,i_saved:integer; { positions }
var digits_before_dot,digits_after_dot:integer;
begin

{ at beginning time
  "i" - is already set to character in string "s";
  array "as" is already initialized;
  coordinate mode "coord_mode" is already known;
}
with b123 do begin { variant record ,b1=b2[1]=b3[1]; b2[2]=b3[2] }

1: { we return to this label if token is not ready still }

b1:=s[i];
isa:=as[b1];   { type of this character }



if isa=is_control
    then begin {1}

 if b1=new_line_code
 then
   begin
   Readline; { skips to next line, sets new "s" and "i" }
   if in_string then begin ER_LEX(11); PutStr2; goto 99; end;
   { ERROR= end of line appears in string constant }
   goto 1;
   end
 else

 if b1=endfile_code
 then
  begin
  if in_comment then ER_LEX(12);
  { ERROR = end of file appears in comment }
  DT:=eof_desk;
  goto 99;
  end
 else

 { others are control characters; }
 { they set "DT" field and then form Rigal list/tree structure }
{$IFDEF MIF}
 if not in_string then
{$ENDIF}

 begin{2}
  if in_comment then begin ER_LEX(13); in_comment:=false; end;
  { ERROR = control char in comment }
  if in_string  then begin ER_LEX(14); PutStr2; goto 99;
                      { will take control character next time }
                     end;
  { ERROR = control char in string }
  DT:=Cont_char_to_dt(b1);
  I:=I+1;
  If (DT=set_coord)and(as[s[i]]=is_digit)
  { this control character sets coordinate to value given in input }
     then begin
          Coord_mark:=TAKE_DIGITS(J);
          Last_mark_byte_number:=line_byte_number+i;
          I:=I+J;
          goto 1; { DOES NOT RETURNS ! }
          end;
  goto 99;
 end; {2}
{NEVER HERE}
end; {1}

{ all the following executes AFTER check of is_control }

{b3[1]:=s[i];}     { this character }
b3[2]:=s[i+1];   { next }
b3[3]:=s[i+2];   { next }

if in_comment    { CHECK FOR END OF COMMENT }
 {THIS part never appears in MIF input, since there is no in_comment status}

   then begin {1}
  { we are in comment;
    here only comments that have some special end mark are processed }
  if pascal_comment then begin {2}
     if  b1='}' then begin inc{3}(i); in_comment:=false; goto 1;end;
     if  b2='*)' then begin inc{4}(i,2); in_comment:=false; goto 1; end;
  end {2}
 else
  if c_comment then begin {2}
     if  b2='*/' then begin inc{4}(i,2); in_comment:=false; goto 1;end;
  end {2}
  ;
 inc{3}(i);
 goto 1;
 end;{1}


{$IFDEF MIF}
if in_string then begin{1}
  if b1='''' then begin PutStr; {jncx}inc(i); goto 99; end
                  {End if MIF constant}
  else
  if str_constlen=10 then begin PutStr;in_string:=true;{jnc}inc(str_constlen);
          {Becomes 11; no shift in input performed, ends part of constant}
                                goto 99; end
  else
  if  str_constlen=11 then begin
      {immediately afrer previous case; starts next part of constant}
                           StrBegin;{sets str_constlen to 0}
                           is_2quote:=false;
                           StrAdd(b1);
                           {jncx}inc(i);
                           goto 1; end
  else   begin
         StrAdd(b1);  {jncx}inc(i);   goto 1; end ; {Normal case}
  end;{1}
if b1='`' then begin StrBegin;is_2quote:=false;{jncx}inc(i);goto 1;end;
           {Starts new MIF text constant}
if b1='#' then begin Readline; goto 1; end; {MIF comment}




{$ELSE}
if in_string

{ CHECK FOR END OF STRING or SOMETHING SPECIAL IN STRING }

    then begin {1}




if pascal_string then begin {2}
         if b1='''' then begin  {3}

            if b2[2]='''' then begin StrAdd('''');
                                     inc{4}(i,2);
                                     goto 1;end
            { this allow to save '''' as '' }


            else begin Putstr;inc{3}(i);goto 99;end;
            end {3}
         else begin {3}
              StrAdd(b1);
              inc{3}(i);
              goto 1;
              end   {3}
         end;  {2}
if modula_string then begin {2}
     if is_2quote and (b1='"')  then
            begin
               if b2[2]='"' then begin StrAdd('"');Inc{4}(i,2);goto 1;end
               else              begin Putstr;inc{3}(i);goto 99;end;
            end;
     if not(is_2quote) and (b1='''') then
            begin Putstr2;inc{3}(i);goto 99;end
     else begin  {3}

          if b1='\' then
             begin
             StrAdd(b1);
             StrAdd(b2[2]);
             { this allows to save \? as ? even if \" appears}
             inc{4}(i,2);
             goto 1;
          end;

          StrAdd(b1);
          inc{3}(i);
          goto 1;
          end;  {3}
     end    {2}
end ;  {1}

 {$ENDIF}

{ all the following executes AFTER check for in_string & in_comment }

if isa=is_special then begin{1}
 {THIS part never appears in MIF input, since there is no is_special}

 if pascal_comment then begin{2}
    if (b2='(*')
       then begin in_comment:=true;inc{4}(i,2);goto 1;end;
    if (b1='{')and(b2[2]<>'$')
       then begin in_comment:=true;inc{3}(i)  ;goto 1;end;
 end{2}
 else
 if c_comment then begin{2}
    if b2='/*' then begin in_comment:=true;inc{4}(i,2);goto 1;end;
 end {2}
 else
 if ada_comment then begin {2}
    if b2='--' then begin Readline;goto 1; end;
 end {2}
 ;

 if pascal_string then begin {2}
    if b1='''' then begin StrBegin;is_2quote:=false;inc{3}(i);goto 1;end;
 end {2}
 else
 if modula_string then begin {2}
    if b1='''' then begin StrBegin;is_2quote:=false;inc{3}(i);goto 1;end;
    if b1='"'  then begin StrBegin;is_2quote:=true;inc{3}(i);goto 1;end;
 end {2}
 ;
if pascal_lexics then begin {2}
 { SPECIALLY TAKES TURBO PASCAL DIRECTIVE-COMMENTS }
 if (b2='{$') then begin {3}
       j:=0;
       repeat inc{3}(j);
       until (s[i+j]='}')or(as[s[i+j]]=is_control);
       if s[i+j]='}' then inc{3}(j);
       PutAtom(j);
       inc{4}(i,j);
       goto 99;
       end; {3}

 { ADDITIONAL SYMBOLS }
 if (b1='#')or(b1='$')or(b1='%')
   then begin {3}
   inc{3}(i);
   J:=TAKE_LETTERS; { starts from i-th position }
   i:=i-1;
   PutAtom(J+1);  { takes token from i-th position }
   inc{4}(i,j+1);
   goto 99;
   end; {3}

end{2}

else
if c_lexics then begin {2}        { SYMBOLS=  > < }
  { SPECIAL CASES FOR C LANGUAGE }

  if (b3='<<=')or(b3='>>=') then begin
    PutAtom(3); inc{4}(i,3); goto 99;
    end;
  isa:=is_first_of_two;
   { !! in C case <<, >>, >=, <=  will be tested further
     in  TWO_char_symbols section, hence we go to there
     using assignment to "ISA" }

  end {2}
end; {1}

if isa=is_space then begin inc{3}(i); goto 1;end;

if isa=is_letter then begin
   J:=TAKE_LETTERS;
   PutIdent(J);
   I:=I+J;
   goto 99;
   end;


if isa=is_digit then begin {1}
 if c_lexics then begin {2}
 { ADDITIONAL SYMBOLS; HERE hex and octal numbers are saved as
   normal ATOMs }
  if (b1='0')
   then begin {3}
   inc{3}(i);
   J:=TAKE_LETTERS; { starts from i-th position }
   i:=i-1;
   PutAtom(J+1);  { takes token from i-th position }
   inc{4}(i,j+1);
   goto 99;
   end; {3}
 end; {2}


   i_saved:=i; { remember starting position }
   AADR:=TAKE_DIGITS(J);
   digits_before_dot:=j;
   if (j<10)and
      (  ((s[i+j]='.')and(s[i+j+1]='.'))
      or
         (not(s[i+j]in['e','E','.'])) )
   then begin PutNumber;inc{4}(i,j);goto 99;end;
   inc{4}(i,j);
   if s[i]='.' then begin
               inc{3}(i);
               AADR:=TAKE_DIGITS(J);
               digits_after_dot:=j;
               inc{4}(i,j);
               end;
   if s[i] in ['e','E'] then
      begin
      digits_before_dot:=0;
      digits_after_dot:=0;
      inc{3}(i);
      if s[i] in ['+','-'] then inc{3}(i);
      AADR:=TAKE_DIGITS(J);
      inc{4}(i,j);
      end;
   J:=i-i_saved;
   i:=i_saved; { to set "i" to starting position }
   PutFloat(J,digits_before_dot,digits_after_dot);
   inc{4}(i,j);
   goto 99;
   end;{1}

if isa=is_first_of_two then begin {1}
   if b2[2] in set_of_second_of_two then
      for j:=1 to two_char_symbols_num do
         if b2=two_char_symbols[j] then begin
            PutAtom(2);I:=I+2;goto 99;
            end
   end;{1}

PutAtom(1);inc{3}(i);
end; { with}
99:;
end; { Procedure }



Function TAKE_LETTERS:integer;
{**************************************}
label 99;
{ Reads only letters, digits and underscores.
  returns number of characters read }

 var JJ:integer; c:char;
 begin
   JJ:=0;
   while true do begin
     c:=s[i+jj];
     isa:=as[c];
     if (isa=is_letter)or(isa=is_digit)or(isa=is_underscore)
        then begin
             if to_uppercase then s[i+jj]:=upcase_tab[c];
             inc{3}(jj)
             end
        else begin
             TAKE_LETTERS:=jj;goto 99;
             end;
   end;
99:;
 end;




Function TAKE_DIGITS(var jj:integer):longint;
{************************************************}
  label 99;
  var summator:longint; c:char;
   begin
    JJ:=0; summator:=0;
    while true do begin
       c:=s[i+jj];
       if as[c]=is_digit then
         begin summator:=summator*10+ord(c)-ord('0');inc{3}(jj);end
       else begin TAKE_DIGITS:=summator;goto 99;end;
    end;
99:;
end;



(*begin*)
{ PRESS F8 when debugging ! }
(*INITIALIZE_SCAN_VARIABLES;*)

end.