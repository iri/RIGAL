
{$IFDEF WIN}

 const done76:boolean=false;
   { controlls if global memory blocks GP1 and GP2 are
     already allocated by #CALL_PAS(76) }
 var GP1,GP2:Word; { handle to global memory block     }
{$ENDIF}
{===========================================================}
Procedure USE_104(p1,p2,p3:a;var rez:a); { EXECUTE A FILE}
    { EXECUTE A FILE WITH (default) return message wm_user+105}
 begin
   rez:=NULL;
   {$IFDEF WIN}
    if PLSTR(P1,STR,L,true,SV1) then begin
       if not PLNUM(p2,IM[2]) then IM[2]:=105;
       rez:=long_to_atom(Wexec(@STR,sw_normal,IM[2]));
     end;
   {$ENDIF}
 end;
{****************************************}
Procedure USE_109(p1,p2,p3:a;var rez:a); { CUT A FILE}
 var f1,f2:text;s:string;i:integer;

 begin

    if PLSTR(P1,STR,L,true,SV1) then begin
     if PLSTR(P2,STR,L,true,SV2) then begin
         Assign(f1,SV1);Reset(f1);
         Assign(f2,SV2);Rewrite(f2);
         while not(eof(f1)) do begin
          readln(f1,s);
          i:=pos(';',s);
          if i=0 then writeln(f2,s)
          else if i<>1 then writeln(f2,copy(s,1,i-1));
         end;
         Close(f1);Close(f2);
     end;end;
 end;
{===========================================================}
Procedure USE_106(p1,p2,p3:a;var rez:a);
   { EXECUTE A FILE WITH (default) return message wm_user+104}
 begin
   rez:=NULL;
   {$IFDEF WIN}
     if PLSTR(P1,STR,L,true,SV1) then begin
       if not PLNUM(p2,IM[2]) then IM[2]:=104;
       rez:=long_to_atom(Wexec(@STR,sw_normal,IM[2]));
     end;
   {$ENDIF}
 end;

{===========================================================}
Procedure USE_107(p1,p2,p3:a;var rez:a); { EXECUTE A BATCH file}
 begin
   rez:=NULL;
   {$IFDEF WIN}
    if PLSTR(P1,STR,L,true,SV1) then begin
    rez:=long_to_atom(Winexec(@STR,sw_normal));
     end;
   {$ENDIF}
 end;


Procedure USE_101(p1,p2,p3:a;var rez:a); {LOAD LIBRARY}
 { Loads DLL Library, is unsuccesful returns NULL, else returns
   library handle; handle is wrong if it is less than 32 }
 { handle return codes are:
(0) no memory
(2) File is absent and the dialogue with
     request to find it was unsuccessful
(5) attempt to link task
(6) multiple data segments
(10) invalid Windows version
(11) invalid EXE file
(12) OS/2 app
(13) DOS 4.0 app
(14) Invalid EXE type
(15) not protect mode

 }
{$IFDEF WIN} var pc:pchar;  { place for library name }
             handle:Thandle; { handle (word) }
{$ENDIF}
 begin
 rez:=NULL;
{$IFDEF WIN}
 GetMem(pc,80);
 if pc=nil then begin rez:=Long_to_atom(-1);exit;end;
                     { no memory 80 bytes }
 if not PLSTR(P1,STR,L,true,SV1) then begin
             rez:=Long_to_atom(-2);exit;end; { wrong parameter }
 StrPcopy(pc,SV1);
 handle:=LoadLibrary(pc);
 rez:=Long_to_atom(handle);
 Freemem(pc,80);
{$ENDIF}
 end;

{=================================================================}
{$IFDEF win}
Function Split_Pchar(pc:Pchar;len:integer):a;
{ The function splits one big PCHAR array "pc" of
   length "len" to many atoms,  cancatenated in list }
{ here the atoms never can be used as identifiers,
  so the are not checked for being identifiers }
  var A1:A;
      A2:a;
      c_pos { current position in "pc" }
      :integer;
  begin
    A1:=NULL;
    c_pos:=0;
    while c_pos<len do
              begin           (*4*)
            { THE FIRST PARTS OF LARGE "ATOM" }
              if len-c_pos>80 then begin (*5*)
                 PUTATM(pc[c_pos],80,ATM);
                 Gets1(a2,x.sa);
                 with x.sad^ do begin dtype:=ATOM;Name:=ATM;end;
                 c_pos:=c_pos+80;
                 end          (*5*)
              else begin      (*5*)
             { THE ONE LAST PART OF LARGE "ATOM" }
                 PUTATM(pc[c_pos],len-c_pos,aTM);
                 Gets1(a2,x.sa);
                 with x.sad^ do begin dtype:=ATOM;Name:=ATM;end;
                 c_pos:=len;
                 end;         (*5*)

              LCONC(a1,a2);
              end;           (*4*)
   Split_Pchar:=a1;
 end;
{$ENDIF}


Procedure USE_102(p1,p2,p3:a;var rez:a); {ACCESS LIBRARY FUNTION}
{$IFDEF WIN}
{ Access to library (handle is P1) function with
  name in P2 and pass list of parameters from  P3;
  Returns error code 1000..1020 or return parameter list from
  the library function
 ERROR CODES
 1000   #CALL_PAS(76) was not called
 1001   1st paramter is not number
 1002   2nd paramter is not atom
 1003   3 handle is less than 32, Library was not opened for access
 1004   no memory 80 bytes
 1005   parameters are not formed in list,
       possible atom instead of list
 1006   function not found in library
        (function must be declared as FAR and EXPORT)
 1008   descriptor too small  (see P_max_size in RIF.PAS )
 1009   too many parameters   (see P_max_cnt  in RIF.PAS )
 1010   wrong atoms in list of atoms which must represent
        super long string (only  non numeric atoms allowed)
 1011   wromg element (tree) in parameters
     }

Procedure ERL(code:word);
 var ms:string[110];pc:pchar;
 begin
 case code of
 1000: ms:='  #CALL_PAS(76) was not called';
 1001: ms:='  1st paramter(handle) is not number';
 1002: ms:='  2nd paramter(function name) is not atom';
 1003: ms:='  handle is less than 32, Library was not opened for access';
 1004: ms:='  no memory 80 bytes';
 1005: ms:='  parameters are not formed in list,possible atom instead of list';
 1006: ms:='  function not found in library ';
 1008: ms:='  descriptor too small  (see P_max_size in RIF.PAS )';
 1009: ms:='  too many parameters   (see P_max_cnt  in RIF.PAS )';
 1010: ms:='  wrong atoms in list of atoms which must represent super long string (only  non numeric atoms allowed)';
 1011: ms:='   wromg element (tree) in parameters';
 end;
 GetMem(pc,120);
 StrPCopy(pc,ms);
 MessageBox(0,pc,'Internal error in #CALL_PAS(102..) call',16);
 writeln(out,pc);
 pout(p1);
 pout(p2);
 pout(p3);
 FreeMem(pc,120);
 rez:=Long_to_atom(code);
 end;



var handle:Thandle; { library handle }
    pch:pchar;      { function name  }

{$IFDEF OLDVER}
type tfun=procedure(AP1,AP2:Pointer);
{$ENDIF}
type tfun=procedure(FUNNAME:Pchar;AP1,AP2:Pointer);

var afun:tfun; afar:Tfarproc; {intermed. for function call }

  var PP,PLIST:PTR; AP1,AP2:Pointer; A1,A2:a; pc:pchar;
      mode:word; er,len,fragnum,len1,k:integer;

{$ENDIF}
begin
 rez:=NULL;
{$IFDEF WIN}
 if not done76 then begin ERL(1000);exit;end;
 if not (PLNUM(p1,IM[1])) then begin ERL(1001);exit;end;
 handle:=IM[1];
 GetMem(pch,80);
 if pch=nil then begin ERL(1004);exit;end;;
 if not PLSTR(P2,STR,L,true,SV1) then begin ERL(1002);exit;end;;
 StrPcopy(pch,SV1);
 if handle<32 then begin ERL(1003);exit;end;
 if handle>=32 then begin
    afar:=GetProcAddress(handle,pchar(51){'fun_disp'});
    afun:=Tfun(afar);
{$IFDEF OLDVER}
    afar:=GetProcAddress(handle,pch);
    afun:=Tfun(afar);
{$ENDIF}
    if @afun=nil then begin ERL(1006);exit;end
    else
      begin
 {================}
  AP1:=GlobalLock(GP1);
  AP2:=GlobalLock(GP2);
  P_clear(AP1);   { Rigal->DLL parameters }
  P_clear(AP2);   { DLL->Rigal parameters }
  if P3<>NULL then begin (*0*)
    Pointr(P3,X.SA);
    if X.SMLD^.DTYPE<>LISTMAIN then
      begin ERL(1005);exit;end;
    First(p3,PP);   { Loop along the list of parameters }
    while PP.NEL<>0 do
     begin (*1*)
      if PP.CEL=NULL then
       begin
       er:=p_Add_NULL(ap1);
       if er<>0 then begin ERL(1007+er);exit;end; { ERROR!}
       end
    else
    begin  (*2*)
     POINTR(pp.cel,x.sa);
     if x.smld^.dtype=listmain then begin (*3*)
        First(pp.cel,PLIST);
        fragnum:=1;
        while Plist.NEL<>0 do begin (*4*)
         if plist.CEL<>0 then (* Added 23-NOV-92 *)
          begin   (*5*)
          if PLNUM(plist.cel,IM[1]) then begin
             system.Str(IM[1],SV1);
             { StrPCopy(STR,SV1);}
             L:=Length(SV1);
             if fragnum=1 then er:=p_Add_pchar(ap1,@SV1[1],L)
                          else er:=p_App_pchar(ap1,@SV1[1],L);
             Inc(fragnum);
             if er<>0 then begin ERL(1007+er);exit;end; { ERROR!}
             end else
          if PLSTR(plist.cel,STR,L,false,SV1) then
             begin
             if fragnum=1 then er:=p_Add_pchar(ap1,@STR,L)
                          else er:=p_App_pchar(ap1,@STR,L);
             Inc(fragnum);
             if er<>0 then begin ERL(1007+er);exit;end; { ERROR!}
             end
          else begin ERL(1010);exit;end; {ERROR}
          end; (*5*)
          Next(PLIST);
          end; (*4*)
        end (*3*)
      else if PLSTR(PP.CEL,STR,L,false,SV1) then
       begin
       er:=p_Add_pchar(ap1,@STR,L); { Atom of length 0 is also possible}
       if er<>0 then begin ERL(1007+er);exit;end; { ERROR!}
       end
      else if PLNUM(PP.cel,IM[1])
       then begin
       er:=p_Add_plong(ap1,IM[1]);
       if er<>0 then begin ERL(1007+er);exit;end; { ERROR!}
       end
      else begin ERL(1011);exit;end; { ERROR !}
    ;
    end; (*2*)
   Next(PP);
   end;  (*1*)
  end; (* 0 *)
  afun(pch,AP1,AP2); { LIBRARY PROCEDURE NAME }
  k:=1;
  repeat  { Loop along the result parametres }
     a1:=NULL;
     mode:=P_GetParm(AP2,k,LEN,pc,IM[1]);
     { if mode=1 then 5th parameter is used,
       otherwise - 3rd and 4th }
     case mode of
     0: exit;  { End of loop (normal) }
     1: MKNUMB(IM[1],a1);
     2: begin { create atom }   (*2*)
        { Value of pc is returned }

      { CASE WITH SINGLE ATOM }
        if (len<>0)and(len<=80) then begin  (*3*)
           ID := pc[0] in LETTER;
           For i:=0 to len-1 do
             ID := ID AND ( pc[i] IN SYMBOLS ) ;
           PUTATM(pc[0],len,ATM); (* makes A-Address *)
           GETS1(a1,x.SA);      (* makes S-Address *)
           with x.sad^ do begin  (* fills descriptor *)
             if ID then dtype:=IDATOM else dtype:=ATOM;
             NAME:=ATM;
             end;
           end (*3*)
        else

        { CASE WITH LARGE "ATOM" }
        if (len>80) then begin (*3*)
           a1:=Split_Pchar(pc,len);
           end (*3*)
        else
        a1:=NULL;  { SAME as 'NULL' protocol value }
        end; (*2*)
     4: a1:=NULL; { SAME as string of length 0 }
     end;
  LCONC(rez,a1);
  Inc(k);
  until false;

  {===============}
      end;
    end;
 Freemem(pch,80);
{$ENDIF}
end;

Procedure USE_103(p1,p2,p3:a;var rez:a); {LOAD LIBRARY}
 begin
 {$IFDEF WIN}
  IF not PLNUM(p1,IM[1]) then Exit;
  if IM[1]>=32 then FreeLibrary(Im[1]);
 {$ENDIF}
 end;

Procedure USE_76(p1,p2,p3:a;var rez:a); {CREATE P1P2}
{ Allocates piece of global memory }
 {If successful , returns 1st argument,
  Utherwise returns NULL  }
  begin
  {$IFDEF WIN}
  rez:=0;
  done76:=true;
  rez:=p1;
  GP1:=GlobalAlloc(gmem_moveable,sizeof(pmain_type));
  if GP1=0 then rez:=0;
  GP2:=GlobalAlloc(gmem_moveable,sizeof(pmain_type));
  if GP2=0 then rez:=0;
  {$ENDIF}
  end;



Procedure USE_117(p1,p2,p3:a;var rez:a);
{ Calls LIBRARY procedure FARDLL from
  Dynamic Link Library
  Returns list of result parameters
  or NULL if call was unsuccessful
  String of length 0 is accepted as NULL
}
  {$IFDEF DLL}
  var PP,PLIST:PTR; AP1,AP2:Pointer; A1,A2:a; pc:pchar;
      mode:word; er,len,fragnum,len1,k:integer;
  {$ENDIF}
  begin
  Rez:=0;
  {$IFDEF DLL}
  AP1:=GlobalLock(GP1);
  AP2:=GlobalLock(GP2);
  P_clear(AP1);   { Rigal->DLL parameters }
  P_clear(AP2);   { DLL->Rigal parameters }
  First(p1,PP);   { Loop along the list of parameters }
  while PP.NEL<>0 do
   begin (*1*)
    if PP.CEL=NULL then
       begin
       er:=p_Add_NULL(ap1);
       if er<>0 then Exit; { ERROR!}
       end
    else
    begin  (*2*)
     POINTR(pp.cel,x.sa);
     if x.smld^.dtype=listmain then begin (*3*)
        First(pp.cel,PLIST);
        fragnum:=1;
        while Plist.NEL<>0 do  begin (*4*)
         if plist.CEL<>0 then (* Added 23-NOV-92 *)
          begin   (*5*)
          if PLSTR(plist.cel,STR,L,false,SV1) then
             begin
             if fragnum=1 then er:=p_Add_pchar(ap1,@STR,L)
                          else er:=p_App_pchar(ap1,@STR,L);
             Inc(fragnum);
             if er<>0 then Exit; { ERROR!}
             end
          else EXIT; {ERROR}
          end; (*5*)
          Next(PLIST);
          end; (*4*)
        end (*3*)
      else if PLSTR(PP.CEL,STR,L,false,SV1) then
       begin
       er:=p_Add_pchar(ap1,@STR,L); { Atom of length 0 is also possible}
       if er<>0 then Exit; { ERROR!}
       end
      else if PLNUM(PP.cel,IM[1])
       then begin
       er:=p_Add_plong(ap1,IM[1]);
       if er<>0 then Exit; { ERROR!}
       end
      else Exit { ERROR !}
    ;
    end; (*2*)
   Next(PP);
   end;  (*1*)
  RFFARDLL(AP1,AP2); { LIBRARY PROCEDURE NAME }
  k:=1;
  repeat  { Loop along the result parametres }
     a1:=NULL;
     mode:=P_GetParm(AP2,k,LEN,pc,IM[1]);
     { if mode=1 then 5th parameter is used,
       otherwise - 3rd and 4th }
     case mode of
     0: exit;  { End of loop (normal) }
     1: MKNUMB(IM[1],a1);
     2: begin { create atom }   (*2*)
        { Value of pc is returned }

      { CASE WITH SINGLE ATOM }
        if (len<>0)and(len<=80) then begin  (*3*)
           ID := pc[0] in LETTER;
           For i:=0 to len-1 do
             ID := ID AND ( pc[i] IN SYMBOLS ) ;
           PUTATM(pc[0],len,ATM); (* makes A-Address *)
           GETS1(a1,x.SA);      (* makes S-Address *)
           with x.sad^ do begin  (* fills descriptor *)
             if ID then dtype:=IDATOM else dtype:=ATOM;
             NAME:=ATM;
             end;
           end (*3*)
        else

        { CASE WITH LARGE "ATOM" }
        if (len>80) then begin (*3*)
           a1:=Split_Pchar(pc,len);
           end (*3*)
        else
        a1:=NULL;  { SAME as 'NULL' protocol value }
        end; (*2*)
     4: a1:=NULL; { SAME as string of length 0 }
     end;
  LCONC(rez,a1);
  Inc(k);
  until false;
  {$ENDIF}
  end;

Procedure USE_118(p1,p2,p3:a;var rez:a);
{ Calls LIBRARY procedure FARDLL from
  Dynamic Link Library
  Returns list of result parameters
  or NULL if call was unsuccessful
  String of length 0 is accepted as NULL
}
  {$IFDEF DLL}
  var PP,PLIST:PTR; AP1,AP2:Pointer; A1,A2:a; pc:pchar;
      mode:word; er,len,fragnum,len1,k:integer;
  {$ENDIF}
  begin
  Rez:=0;
  {$IFDEF DLL}
  AP1:=GlobalLock(GP1);
  AP2:=GlobalLock(GP2);
  P_clear(AP1);   { Rigal->DLL parameters }
  P_clear(AP2);   { DLL->Rigal parameters }
  First(p1,PP);   { Loop along the list of parameters }
  while PP.NEL<>0 do
   begin (*1*)
    if PP.CEL=NULL then
       begin
       er:=p_Add_NULL(ap1);
       if er<>0 then Exit; { ERROR!}
       end
    else
    begin  (*2*)
     POINTR(pp.cel,x.sa);
     if x.smld^.dtype=listmain then begin (*3*)
        First(pp.cel,PLIST);
        fragnum:=1;
        while Plist.NEL<>0 do begin (*4*)
         if plist.CEL<>0 then (* Added 23-NOV-92 *)
          begin   (*5*)
          if PLSTR(plist.cel,STR,L,false,SV1) then
             begin
             if fragnum=1 then er:=p_Add_pchar(ap1,@STR,L)
                          else er:=p_App_pchar(ap1,@STR,L);
             Inc(fragnum);
             if er<>0 then Exit; { ERROR!}
             end
          else EXIT; {ERROR}
          end; (*5*)
          Next(PLIST);
          end; (*4*)
        end (*3*)
      else if PLSTR(PP.CEL,STR,L,false,SV1) then
       begin
       er:=p_Add_pchar(ap1,@STR,L); { Atom of length 0 is also possible}
       if er<>0 then Exit; { ERROR!}
       end
      else if PLNUM(PP.cel,IM[1])
       then begin
       er:=p_Add_plong(ap1,IM[1]);
       if er<>0 then Exit; { ERROR!}
       end
      else Exit { ERROR !}
    ;
    end; (*2*)
   Next(PP);
   end;  (*1*)
  PFFARDLL(AP1,AP2); { LIBRARY PROCEDURE NAME }
  k:=1;
  repeat  { Loop along the result parametres }
     a1:=NULL;
     mode:=P_GetParm(AP2,k,LEN,pc,IM[1]);
     { if mode=1 then 5th parameter is used,
       otherwise - 3rd and 4th }
     case mode of
     0: exit;  { End of loop (normal) }
     1: MKNUMB(IM[1],a1);
     2: begin { create atom }   (*2*)
        { Value of pc is returned }

      { CASE WITH SINGLE ATOM }
        if (len<>0)and(len<=80) then begin  (*3*)
           ID := pc[0] in LETTER;
           For i:=0 to len-1 do
             ID := ID AND ( pc[i] IN SYMBOLS ) ;
           PUTATM(pc[0],len,ATM); (* makes A-Address *)
           GETS1(a1,x.SA);      (* makes S-Address *)
           with x.sad^ do begin  (* fills descriptor *)
             if ID then dtype:=IDATOM else dtype:=ATOM;
             NAME:=ATM;
             end;
           end (*3*)
        else

        { CASE WITH LARGE "ATOM" }
        if (len>80) then begin (*3*)
           a1:=Split_Pchar(pc,len);
           end (*3*)
        else
        a1:=NULL;  { SAME as 'NULL' protocol value }
        end; (*2*)
     4: a1:=NULL; { SAME as string of length 0 }
     end;
  LCONC(rez,a1);
  Inc(k);
  until false;
  {$ENDIF}
  end;

Procedure USE_77(p1,p2,p3:a;var rez:a);
{ Calls LIBRARY procedure FARDLL from
  Dynamic Link Library
  Returns list of result parameters
  or NULL if call was unsuccessful
  String of length 0 is accepted as NULL
}
  {$IFDEF DLL}
  var PP,PLIST:PTR; AP1,AP2:Pointer; A1,A2:a; pc:pchar;
      mode:word; er,len,fragnum,len1,k:integer;
  {$ENDIF}
  begin
  Rez:=0;
  {$IFDEF DLL}
  AP1:=GlobalLock(GP1);
  AP2:=GlobalLock(GP2);
  P_clear(AP1);   { Rigal->DLL parameters }
  P_clear(AP2);   { DLL->Rigal parameters }
  First(p1,PP);   { Loop along the list of parameters }
  while PP.NEL<>0 do
   begin (*1*)
    if PP.CEL=NULL then
       begin
       er:=p_Add_NULL(ap1);
       if er<>0 then Exit; { ERROR!}
       end
    else
    begin  (*2*)
     POINTR(pp.cel,x.sa);
     if x.smld^.dtype=listmain then begin (*3*)
        First(pp.cel,PLIST);
        fragnum:=1;
        while Plist.NEL<>0 do begin (*4*)
         if plist.CEL<>0 then (* Added 23-NOV-92 *)
          begin   (*5*)
          if PLSTR(plist.cel,STR,L,false,SV1) then
             begin
             if fragnum=1 then er:=p_Add_pchar(ap1,@STR,L)
                          else er:=p_App_pchar(ap1,@STR,L);
             Inc(fragnum);
             if er<>0 then Exit; { ERROR!}
             end
          else EXIT; {ERROR}
          end;(*5*)
          Next(PLIST);
          end; (*4*)
        end (*3*)
      else if PLSTR(PP.CEL,STR,L,false,SV1) then
       begin
       er:=p_Add_pchar(ap1,@STR,L); { Atom of length 0 is also possible}
       if er<>0 then Exit; { ERROR!}
       end
      else if PLNUM(PP.cel,IM[1])
       then begin
       er:=p_Add_plong(ap1,IM[1]);
       if er<>0 then Exit; { ERROR!}
       end
      else Exit { ERROR !}
    ;
    end; (*2*)
   Next(PP);
   end;  (*1*)
  SFFARDLL(AP1,AP2); { LIBRARY PROCEDURE NAME }
  k:=1;
  repeat  { Loop along the result parametres }
     a1:=NULL;
     mode:=P_GetParm(AP2,k,LEN,pc,IM[1]);
     { if mode=1 then 5th parameter is used,
       otherwise - 3rd and 4th }
     case mode of
     0: exit;  { End of loop (normal) }
     1: MKNUMB(IM[1],a1);
     2: begin { create atom }   (*2*)
        { Value of pc is returned }

      { CASE WITH SINGLE ATOM }
        if (len<>0)and(len<=80) then begin  (*3*)
           ID := pc[0] in LETTER;
           For i:=0 to len-1 do
             ID := ID AND ( pc[i] IN SYMBOLS ) ;
           PUTATM(pc[0],len,ATM); (* makes A-Address *)
           GETS1(a1,x.SA);      (* makes S-Address *)
           with x.sad^ do begin  (* fills descriptor *)
             if ID then dtype:=IDATOM else dtype:=ATOM;
             NAME:=ATM;
             end;
           end (*3*)
        else

        { CASE WITH LARGE "ATOM" }
        if (len>80) then begin (*3*)
           a1:=Split_Pchar(pc,len);
           end (*3*)
        else
        a1:=NULL;  { SAME as 'NULL' protocol value }
        end; (*2*)
     4: a1:=NULL; { SAME as string of length 0 }
     end;
  LCONC(rez,a1);
  Inc(k);
  until false;
  {$ENDIF}
  end;
