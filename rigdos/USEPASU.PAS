{ VERSION  of  USEPASU.PAS:
               ====== 1.50 ======
        accords only to TURBO.TPL  with time " 01:50" (or later)
  REVISIONS:
  Since version   1.46 , 25-mar-1991 :
   The "USEs units" (all but DEFINE) directive is ported from
   interface part to implementation part; TURBO.TPL is changed !
  Since version  1.47 , 8-apr-1991 :
   DEFINE DOSCRT appeared and disappeared for some cases.
   DEFINE SDLBL  appeared for some SDL cases.
  Since version 1.50 , 8-apr-1991 :
   No more define/undefine options.
  Since version 2.0 #CALL_PAS(46 , 45) return their argument to
   the interpreter.
  Since version 2.03 #CALL_PAS( 35,36,37,38 ) present,
   New scaner ( unit SCAN ) is added to implementation part.
  Since version 2.06 #CALL_PAS(73 74 75) present
  Since version 2.08 #CALL_PAS(76 77) present
  Since version 2.09 Conditional compilation $DLL for USE_PAS(76 77)
                     present
  Since version 2.12 #CALL_PAS(78 $N) used to restrict PRINT depth
  Since version 2.14
 #CALL_PAS(80 SIGN $R1 $R2) used for operations
   with #FATOM atoms and real numbers
 #CALL_PAS(81 APPL TOPIC) used for Window start up
 #CALL_PAS(82 MESS_TITLE MESS [code] ) used for the message boxes
 #CALL_PAS(83 QUESTION [ Standard_value ] ) used  for the input boxes
 #CALL_PAS(84 Modenum ModeVal) modifies CRT Window sizes before first output
   [ 1,2 WindowOrg (Pix);3,4 Windowsize (pix);5,6 SeceenSize (symbols) ]
  Since version 2.15
 #CALL_PAS(85 TEXT)- Uppercase
 #CALL_PAS(86 TEXT) - Lowercase
 #CALL_PAS(87 TEXT V1 [V2]) - Substr(TEXT,V1,V2)
 #CALL_PAS(88 TEXT1 TEXT2)  - Position of text1 in text2
 HOW TO USE :
   USEr's private functions are 101,102...
   Change "implementation" part only!

 HOW TO RECOMPILE :
   Rigal compiler refers to USEPasu.pas file
   if such file exist in current directory,
   otherwise copies it from distributive directory.
   Interpreter refers to USEPasu.pas in source directory only,
   if you haven't source code, then you can't change the interpreter.

 ERRORS : If Turbo Pascal compiler said "Unit version mismatch",
   it means you have old USEPASU.PAS in your directory, or
   you changed the interface part. Don't change it ! It is
   fixed yet in TURBO.TPL units. This interface part and TURBO.TPL
   must be of the same version.
   If you start work with NEW Rigal version - remove old USEPASU.PAS
   from YOUR directory !!!
   Of'course, USEPASU.TPU is not included in TURBO.TPL.

 COMPATIBILITY : All old options are working the same way as they
   appeared, except No.26 (Window) changed its format.
   Your own-written options compatibility is not supported if
   you had USEd version 1.44 or earlier !!!

 CONTACT : (0132)226997, Vadim Engelson,
           SU-226250,LUMII,Rainis b.29,Riga.
           e-mail vadim@lumii.lat.su
           If you have problems, learn UNITS
           and UNIT LIBRARIES in Borland's guide
           and then tell me:
           date,time,size of TURBO.TPL you USE and
           version of USEPASU.PAS

*****************************************************
*****************************************************
*****    DON'T CHANGE  TEXT  HERE  !  ***************}
Unit USEpasu;
 interface USEs Define;
{Procedure USE_X( COMPILER OR INTERPRETER ACCESS
      p1,p2,p3:a;  arguments
      var rez:a);}

Procedure USE_1(p1,p2,p3:a;var rez:a);
Procedure USE_2(p1,p2,p3:a;var rez:a);
Procedure USE_3(p1,p2,p3:a;var rez:a);
Procedure USE_4(p1,p2,p3:a;var rez:a);
Procedure USE_5(p1,p2,p3:a;var rez:a);
Procedure USE_6(p1,p2,p3:a;var rez:a);
Procedure USE_7(p1,p2,p3:a;var rez:a);
Procedure USE_8(p1,p2,p3:a;var rez:a);
Procedure USE_9(p1,p2,p3:a;var rez:a);
Procedure USE_10(p1,p2,p3:a;var rez:a);
Procedure USE_11(p1,p2,p3:a;var rez:a);
Procedure USE_12(p1,p2,p3:a;var rez:a);
Procedure USE_13(p1,p2,p3:a;var rez:a);
Procedure USE_14(p1,p2,p3:a;var rez:a);
Procedure USE_15(p1,p2,p3:a;var rez:a);
Procedure USE_16(p1,p2,p3:a;var rez:a);
Procedure USE_17(p1,p2,p3:a;var rez:a);
Procedure USE_18(p1,p2,p3:a;var rez:a);
Procedure USE_19(p1,p2,p3:a;var rez:a);
Procedure USE_20(p1,p2,p3:a;var rez:a);
Procedure USE_21(p1,p2,p3:a;var rez:a);
Procedure USE_22(p1,p2,p3:a;var rez:a);
Procedure USE_23(p1,p2,p3:a;var rez:a);
Procedure USE_24(p1,p2,p3:a;var rez:a);
Procedure USE_25(p1,p2,p3:a;var rez:a);
Procedure USE_26(p1,p2,p3:a;var rez:a);
Procedure USE_27(p1,p2,p3:a;var rez:a);
Procedure USE_28(p1,p2,p3:a;var rez:a);
Procedure USE_29(p1,p2,p3:a;var rez:a);
Procedure USE_30(p1,p2,p3:a;var rez:a);
Procedure USE_31(p1,p2,p3:a;var rez:a);
Procedure USE_32(p1,p2,p3:a;var rez:a);
Procedure USE_33(p1,p2,p3:a;var rez:a);
Procedure USE_34(p1,p2,p3:a;var rez:a);
Procedure USE_35(p1,p2,p3:a;var rez:a);
Procedure USE_36(p1,p2,p3:a;var rez:a);
Procedure USE_37(p1,p2,p3:a;var rez:a);
Procedure USE_38(p1,p2,p3:a;var rez:a);
Procedure USE_39(p1,p2,p3:a;var rez:a);
Procedure USE_40(p1,p2,p3:a;var rez:a);
Procedure USE_41(p1,p2,p3:a;var rez:a);
Procedure USE_42(p1,p2,p3:a;var rez:a);
Procedure USE_43(p1,p2,p3:a;var rez:a);
Procedure USE_44(p1,p2,p3:a;var rez:a);
Procedure USE_45(p1,p2,p3:a;var rez:a);
Procedure USE_46(p1,p2,p3:a;var rez:a);
Procedure USE_47(p1,p2,p3:a;var rez:a);
Procedure USE_48(p1,p2,p3:a;var rez:a);
Procedure USE_49(p1,p2,p3:a;var rez:a);
Procedure USE_50(p1,p2,p3:a;var rez:a);
Procedure USE_51(p1,p2,p3:a;var rez:a);
Procedure USE_52(p1,p2,p3:a;var rez:a);
Procedure USE_53(p1,p2,p3:a;var rez:a);
Procedure USE_54(p1,p2,p3:a;var rez:a);
Procedure USE_55(p1,p2,p3:a;var rez:a);
Procedure USE_56(p1,p2,p3:a;var rez:a);
Procedure USE_57(p1,p2,p3:a;var rez:a);
Procedure USE_58(p1,p2,p3:a;var rez:a);
Procedure USE_59(p1,p2,p3:a;var rez:a);
Procedure USE_60(p1,p2,p3:a;var rez:a);
Procedure USE_61(p1,p2,p3:a;var rez:a);
Procedure USE_62(p1,p2,p3:a;var rez:a);
Procedure USE_63(p1,p2,p3:a;var rez:a);
Procedure USE_64(p1,p2,p3:a;var rez:a);
Procedure USE_65(p1,p2,p3:a;var rez:a);
Procedure USE_66(p1,p2,p3:a;var rez:a);
Procedure USE_67(p1,p2,p3:a;var rez:a);
Procedure USE_68(p1,p2,p3:a;var rez:a);
Procedure USE_69(p1,p2,p3:a;var rez:a);
Procedure USE_70(p1,p2,p3:a;var rez:a);
Procedure USE_71(p1,p2,p3:a;var rez:a);
Procedure USE_72(p1,p2,p3:a;var rez:a);
Procedure USE_73(p1,p2,p3:a;var rez:a);
Procedure USE_74(p1,p2,p3:a;var rez:a);
Procedure USE_75(p1,p2,p3:a;var rez:a);
Procedure USE_76(p1,p2,p3:a;var rez:a);
Procedure USE_77(p1,p2,p3:a;var rez:a);
Procedure USE_78(p1,p2,p3:a;var rez:a);
Procedure USE_79(p1,p2,p3:a;var rez:a);
Procedure USE_80(p1,p2,p3:a;var rez:a);
Procedure USE_81(p1,p2,p3:a;var rez:a);
Procedure USE_82(p1,p2,p3:a;var rez:a);
Procedure USE_83(p1,p2,p3:a;var rez:a);
Procedure USE_84(p1,p2,p3:a;var rez:a);
Procedure USE_85(p1,p2,p3:a;var rez:a);
Procedure USE_86(p1,p2,p3:a;var rez:a);
Procedure USE_87(p1,p2,p3:a;var rez:a);
Procedure USE_88(p1,p2,p3:a;var rez:a);
Procedure USE_89(p1,p2,p3:a;var rez:a);
Procedure USE_90(p1,p2,p3:a;var rez:a);
Procedure USE_91(p1,p2,p3:a;var rez:a);
Procedure USE_92(p1,p2,p3:a;var rez:a);
Procedure USE_93(p1,p2,p3:a;var rez:a);
Procedure USE_94(p1,p2,p3:a;var rez:a);
Procedure USE_95(p1,p2,p3:a;var rez:a);
Procedure USE_96(p1,p2,p3:a;var rez:a);
Procedure USE_97(p1,p2,p3:a;var rez:a);
Procedure USE_98(p1,p2,p3:a;var rez:a);
Procedure USE_99(p1,p2,p3:a;var rez:a);
Procedure USE_100(p1,p2,p3:a;var rez:a);
Procedure USE_101(p1,p2,p3:a;var rez:a);
Procedure USE_102(p1,p2,p3:a;var rez:a);
Procedure USE_103(p1,p2,p3:a;var rez:a);
Procedure USE_104(p1,p2,p3:a;var rez:a);
Procedure USE_105(p1,p2,p3:a;var rez:a);
Procedure USE_106(p1,p2,p3:a;var rez:a);
Procedure USE_107(p1,p2,p3:a;var rez:a);
Procedure USE_108(p1,p2,p3:a;var rez:a);
Procedure USE_109(p1,p2,p3:a;var rez:a);
Procedure USE_110(p1,p2,p3:a;var rez:a);
Procedure USE_111(p1,p2,p3:a;var rez:a);
Procedure USE_112(p1,p2,p3:a;var rez:a);
Procedure USE_113(p1,p2,p3:a;var rez:a);
Procedure USE_114(p1,p2,p3:a;var rez:a);
Procedure USE_115(p1,p2,p3:a;var rez:a);
Procedure USE_116(p1,p2,p3:a;var rez:a);
Procedure USE_117(p1,p2,p3:a;var rez:a);
Procedure USE_118(p1,p2,p3:a;var rez:a);
Procedure USE_119(p1,p2,p3:a;var rez:a);
Procedure USE_120(p1,p2,p3:a;var rez:a);
Procedure USE_121(p1,p2,p3:a;var rez:a);
Procedure USE_122(p1,p2,p3:a;var rez:a);
Procedure USE_123(p1,p2,p3:a;var rez:a);
Procedure USE_124(p1,p2,p3:a;var rez:a);
Procedure USE_125(p1,p2,p3:a;var rez:a);
Procedure USE_126(p1,p2,p3:a;var rez:a);
Procedure USE_127(p1,p2,p3:a;var rez:a);
Procedure USE_128(p1,p2,p3:a;var rez:a);
Procedure USE_129(p1,p2,p3:a;var rez:a);
Procedure USE_130(p1,p2,p3:a;var rez:a);
Procedure USE_131(p1,p2,p3:a;var rez:a);
Procedure USE_132(p1,p2,p3:a;var rez:a);
Procedure USE_133(p1,p2,p3:a;var rez:a);
Procedure USE_134(p1,p2,p3:a;var rez:a);
Procedure USE_135(p1,p2,p3:a;var rez:a);
Procedure USE_136(p1,p2,p3:a;var rez:a);
Procedure USE_137(p1,p2,p3:a;var rez:a);
Procedure USE_138(p1,p2,p3:a;var rez:a);
Procedure USE_139(p1,p2,p3:a;var rez:a);
Procedure USE_140(p1,p2,p3:a;var rez:a);
Procedure USE_141(p1,p2,p3:a;var rez:a);
Procedure USE_142(p1,p2,p3:a;var rez:a);
Procedure USE_143(p1,p2,p3:a;var rez:a);
Procedure USE_144(p1,p2,p3:a;var rez:a);
Procedure USE_145(p1,p2,p3:a;var rez:a);
Procedure USE_146(p1,p2,p3:a;var rez:a);
Procedure USE_147(p1,p2,p3:a;var rez:a);
Procedure USE_148(p1,p2,p3:a;var rez:a);
Procedure USE_149(p1,p2,p3:a;var rez:a);
Procedure USE_150(p1,p2,p3:a;var rez:a);


Procedure USEPAS               {INTERPRETER ACCESS}
 ( N : integer;{ Number of option }
    VAR PL:PTR; { Pointer to argument list }
    VAR rez:A );{ Result }

var start_name:string80;
 (* filled by interpreter in INT.PAS,
           by compiler in C3.PAS/PROLOG,
    used in CALL_PAS(105)          *)
{*****************************************************}
{*****************************************************}

implementation

{****************************************************}
{******  CHANGE FOLLOWING TEXT  !   *****************}


  USEs
    Defpage,Stlev,
  Leyer,       Leder,
  TabUSE,      Ruscode,
  Doutu,       Poutlexu,
 {$IFDEF WIN}
     WinCrt,WinDos,RigDDE,RIF,USEIBOX,
     WinProcs,wintypes,strings,wexeclu,

     {$IFDEF DLL} rigimpo, {$ENDIF}  { see USE_76, USE_77 }

 {$ELSE}
     Crt,Dos,
 {$ENDIF}
 Nef,Scan,Scanmif;

{$I USINTER.PAS}

 var X:MPD;

 Function PLSTR(p0:a; { input - S-address}
                 var STRVAL:bl80;{ output: array }
                 var LENVAL:integer;  { length of atom }
                     STRINGFLAG:boolean; { need stringval ? }
                 var STRINGVAL:string) { String }
                 :boolean;
  { Returns array of letters of atom if it is list parameter; }
  { Stringval with the same contest returned only
    if required by StringFlag }
   Var ATM:AA; I:integer;
   begin
     STRINGVAL[0]:=char(0);
     if P0=NULL then PLSTR:=FALSE
     else begin
      POINTR(P0,x.SA);(* access to atom in memory *)
      if NOT (x.sad^.dtype IN ([ATOM..FATOM]-[NUMBER])) then PLSTR:=FALSE
      else begin
        ATM:=x.sad^.NAME;(* access to A-address *)
        POINTA(ATM,STRVAL,LENVAL);(* reads value to STR variable *)
        STRVAL[LENVAL+1]:=#0;
        if STRINGFLAG then begin
          STRINGVAL[0]:=char(LENVAL);
          FOR I:=1 TO LENVAL do STRINGVAL[I]:=STRVAL[I];
         (* and to StringVal variable *)
        end;
        PLSTR:=true;
        end;
      end;
    end; { PLSTR }




Function BC(a:byte):char;
begin if a>=10 then bc:=char(65+a-10)
               else bc:=char(48+a);
 end;

Procedure Dump(adr:a;sad:a); { Physical address }
 type reftype=^byte;
 type refadr =^a;
 var p1:reftype;i,j:byte;p2:refadr;
 begin
 Writeln;
 Writeln(' S-Address=',sad,' Physical=',adr);
 for i:=0 to 9 do begin
  for j:=0 to 3 do begin
   p1:=reftype(longint(adr)+i*4+j);
   write(bc(p1^ shr 4),bc(p1^ and $0F));
   end;
   write(' ');
  for j:=0 to 3 do begin
   p1:=reftype(longint(adr)+i*4+j);
   if p1^>=32 then write(chr(p1^)) else write('.');
   end;
   p2:=refadr(longint(adr)+i*4);
   writeln(' ',refadr(p2)^);
  end;
 end;

{==========================================================================}
{==========================================================================}
{===========================================================================}
{===========================================================================}
{-$DEFINE TABLES}
{$DEFINE NOTABLES}

LABEL 66,101,102,200;
VAR A1,ATM : A;
    I,J,L,I1:INTEGER;
    error_rec_USE:error_rec_type;
    DT : DESCRIPTORTYPE;
    workfile:file;
    C:CHAR;
    ID:BOOLEAN;
    SV1,SV2,SVAR: string;
    STR : bl80;(*For POINTA & PUTATM*)
    IM: array[1..5] of longint;

{$IFDEF TABLES}
Procedure USE_59(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(59,P1,P2,P3,rez);end;
Procedure USE_60(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(60,P1,P2,P3,rez);end;
Procedure USE_61(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(61,P1,P2,P3,rez);end;
Procedure USE_62(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(62,P1,P2,P3,rez);end;
Procedure USE_63(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(63,P1,P2,P3,rez);end;
Procedure USE_64(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(64,P1,P2,P3,rez);end;
Procedure USE_65(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(65,P1,P2,P3,rez);end;
Procedure USE_66(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(66,P1,P2,P3,rez);end;
Procedure USE_67(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(67,P1,P2,P3,rez);end;
Procedure USE_68(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(68,P1,P2,P3,rez);end;
Procedure USE_69(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(69,P1,P2,P3,rez);end;
Procedure USE_70(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(70,P1,P2,P3,rez);end;
Procedure USE_71(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(71,P1,P2,P3,rez);end;
Procedure USE_72(p1,p2,p3:a;var rez:a);begin rez:=NULL;TABDISP(72,P1,P2,P3,rez);end;
{$ENDIF}
{$IFDEF NOTABLES}
Procedure USE_59(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_60(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_61(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_62(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_63(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_64(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_65(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_66(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_67(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_68(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_69(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_70(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_71(p1,p2,p3:a;var rez:a);begin end;
Procedure USE_72(p1,p2,p3:a;var rez:a);begin end;

{$endif}


Procedure USE_105(p1,p2,p3:a;var rez:a);
  (* HOMEDIR *)
 var i:integer;
 {$IFDEF WIN}
 var pch,pchbig:pchar;
 begin
  GetMem(pch,80);
  GetMem(pchbig,80);
  StrPCopy(pch,start_name);
  FileExpand(pchbig,pch);
  start_name:=StrPas(pchbig);
  FreeMem(pch,80);
  FreeMem(pchbig,80);
 {$ELSE}
 begin
 start_name:=Fexpand(start_name);
 {$ENDIF}
 i:=Length(start_name);
 while (i<>1)and(start_name[i]<>'\') do dec(i);
 rez:=Str_to_textatom(Copy(start_name,1,i));  (* Changed in version 2.41 3-FEB-93 *)
 end;

Procedure USE_42(p1,p2,p3:a;var rez:a);
 (* returns current PAGE (very USEful for big algorythms) *)
    begin
          GETS1(rez,x.SA);
          with x.snd^ do begin dtype:=NUMBER;cord:=0;
          VAL:=(rez+1)div(256*256*256);
          if VAL<0 then VAL:=256+VAL;
          end;
    end;

Procedure USE_43(p1,p2,p3:a;var rez:a);
 (* returns #CALL_PAS(42) if current disk in USE,
       0 otherwise. *)
    begin
          GETS1(rez,x.SA);
          with x.snd^ do begin dtype:=NUMBER;cord:=0;
          VOLS(IM[1],IM[2],VAL);
          end;
    end;

Procedure USE_30(p1,p2,p3:a;var rez:a);
begin
 rez:=NULL;
 (*Write atom or number*)
    if  PLSTR(P1,STR,L,true,SV1) then write(SV1)
                  else
                  if PLNUM(P1,IM[1]) then write(IM[1]);
end;

Procedure USE_31(p1,p2,p3:a;var rez:a);
begin
 (*Write atom or number with adding spaces after it or rupping the end*)
 rez:=0;
    if  not PLSTR(P1,STR,L,true,SV1) then
      if not PLNUM(P1,IM[2]) then exit
      else system.STR(IM[2],SV1);
    if PLNUM(P2,IM[1]) then
            begin
            if IM[1]>Length(SV1) then
               for i:=Length(sv1)+1 to IM[1] do SV1[i]:=' ';
            sv1[0]:=chr(IM[1]);
            end;
    write(SV1);
    end;



Procedure USE_5(p1,p2,p3:a;var rez:a);
 begin (* russian->english SDL coding *)
    rez:=P1;
    if PLSTR(P1,STR,L,false,SV1) then begin
      if not SDL_CODING(STR,rez,L,X)
       { here X is Global in USEpasu ! }
       then rez:=p1;
    end;
    end ;


Procedure USE_1(p1,p2,p3:a;var rez:a);
 begin
    rez:=0;
              { Puts an atom (or NULL) to screen.
                USEr's answer (atom, identifier or number ) is returned }
    if PLSTR(P1,STR,L,true,SV1) then Write(SV1);
    READLN(SVAR);(* Enters from screen *)
    rez:=Str_to_atom(SVAR);
  end;

Procedure USE_2(p1,p2,p3:a;var rez:a);
 { SDL/PASCAL Lexical analyser }
 begin rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then LED(SV1,rez);end;

Procedure USE_3(p1,p2,p3:a;var rez:a);
 { SDL/PASCAL Lexical analyser }
 begin rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then LED(SV1,rez);end;


{RIGAL Lexical analyser }
 Procedure USE_14(p1,p2,p3:a;var rez:a);
 begin rez:=0;
 if PLSTR(P1,STR,L,true,SV1) then  LEY(SV1,rez,FALSE,error_rec_USE);
 end;

Procedure USE_15(p1,p2,p3:a;var rez:a);
 begin rez:=0;
 if PLSTR(P1,STR,L,true,SV1) then  LEY(SV1,rez,TRUE,error_rec_USE);
 end;

Procedure USE_16(p1,p2,p3:a;var rez:a);
begin rez:=0;
if PLSTR(P1,STR,L,true,SV1) then begin
       Assign (INFILE[1], SV1);
       {$I-}
       Reset(INFILE[1]);
       If IOresult<>0 then exit;
       Rez:=NULL;
       While not(eof(INFILE[1])) do begin
        READLN(INFILE[1],SVAR);(* Enters from screen *)
        A1:=Str_to_textatom(SVAR); (* Changed in version 2.41 3-FEB-93 *)

{$IFDEF OLD}
        A1:=NULL;
        Val(SVAR,IM[1],L);
        if L=0 then begin
            GETS1(A1,x.SA);
            with x.snd^ do begin dtype:=NUMBER;cord:=0;VAL:=IM[1]; end;
            end
        else
          begin
          if length(SVAR)<>0 then begin
          ID := SVAR[1] in LETTER;
           For i:=1 to length(SVAR) do
            ID := ID AND ( SVAR[i] IN SYMBOLS ) ;
           I:=length(SVAR);
           PUTATM(SVAR[1],I,ATM); (* makes A-Address *)
           GETS1(A1,x.SA);      (* makes S-Address *)
           with x.sad^ do begin  (* fills descriptor *)
            if ID then dtype:=IDATOM else dtype:=ATOM;
            NAME:=ATM;
            end; { with }
          end; {<>0}
    end; {else}
{$ENDIF}


    LCONC(REZ,A1);
   end; {while eof}
   Close(INFILE[1]);
  end;
end;

Procedure USE_4(p1,p2,p3:a;var rez:a);
begin rez:=0;
  (* finds coordinate of atom *)
    if  P1<>0 then begin
        POINTR(P1,x.SA);
        if x.sad^.dtype IN [ATOM..FATOM]-[NUMBER] then A1:=x.sad^.cord
        else if x.snd^.dtype=NUMBER then A1:=x.snd^.cord
        else A1:=0;
       (* make numerical atom *)
        GETS1(rez,x.SA);
        with x.snd^ do begin (* fill descriptor *)
          dtype:=NUMBER;cord:=0;
          VAL:=A1;
        end;
    end;
 end;

Procedure USE_6(p1,p2,p3:a;var rez:a);
 begin
      rez:=P1;
      if PLSTR(P1,STR,L,false,SV1) then begin
        FOR I:=2 TO L do begin
         if ((STR[I]='_')and(STR[I-1]='_')) then
           begin rez:=NULL;exit;end;
        end;
      end;
    end;

Procedure USE_7(p1,p2,p3:a;var rez:a);
 begin
  rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin
    if PLSTR(P2,STR,L,true,SV2) then begin
          Assign(workfile,sv1);
      {$I-} RENAME(workfile,SV2);
            IM[1]:=IOresult; {$I+}
            GETS1(rez,x.SA);with x.snd^ do begin dtype:=NUMBER;cord:=0;VAL:=IM[1];end;
    end;end;end;

Procedure USE_8(p1,p2,p3:a;var rez:a);

 (* DELETEFILE *)
 begin rez:=0;
  if PLSTR(P1,STR,L,true,SV1) then begin
          Assign(workfile,sv1);
    {$I-} ERASE(workfile);
          IM[1]:=IOresult; {$I+}
          GETS1(rez,x.SA);with x.snd^ do begin dtype:=NUMBER;cord:=0;VAL:=IM[1];end;
   end;
  end;

Procedure USE_10(p1,p2,p3:a;var rez:a);

 (* DUMP *)
 begin rez:=0;
    if P1<>0 then begin
    A1:=P1;
    REPEAT
     POINTR(A1,x.SA);
     Dump(x.sa,a1);
     Write(' Another address=');Readln(A1);
    UNTIL A1=0;
    end; end;


Procedure USE_13(p1,p2,p3:a;var rez:a);
begin
 (* Nice PRINT *)
 rez:=0;
    if P1<>0 then begin
      WRITELN; doUT(P1); end;end;

Procedure USE_12(p1,p2,p3:a;var rez:a);
begin rez:=0;
 (* Nice PRINT *)
    if P1<>0 then begin
      WRITELN(out); doUT2(P1);writeln(out); end;end;



Procedure USE_19(p1,p2,p3:a;var rez:a);
begin rez:=0; Randomize;end;

Procedure USE_20(p1,p2,p3:a;var rez:a);
 (*RANDOM*)
   begin rez:=0;
    if PLNUM(P1,IM[1]) then rez:=Long_to_atom(Random(IM[1]));
   end;

Procedure USE_21(p1,p2,p3:a;var rez:a);
 (* ATOM->NUMBER, others->NULL *)
 begin rez:=0;
    if  PLSTR(P1,STR,L,true,SV1) then begin
        IF (SV1[L]='l') or (SV1[L]='L') then SV1:=Copy(SV1,1,L-1);
        Val(SV1,IM[1],L);
        if L=0 then rez:=Long_to_atom(IM[1]);
    { in v.2.20 returns NULL if not numeric value }
    end; end;





var Erlist:a; { used to leave error message list in USEPAS after Scaner
                return it to another USEPAS call later - when it will
                be retrieved }

Procedure USE_35(p1,p2,p3:a; var rez:a);
{ Scaner receives data from file }
{ Format #CALL_PAS(35 $DOS_FILENAME [ $OPTIONS ])  }
{ Returns NULL if file  does not exist }
begin
   rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin { File name }
    if not PLSTR(P2,STR,L,true,SV2) then SV2:=''; { Options }
      INITIALIZE_SCAN_VARIABLES;
      Scaner (1,SV1,SV2,rez,erlist,NULL,0,0);
end;end;

Procedure USE_121(p1,p2,p3:a; var rez:a);
{ Scaner receives data from MIF file }
{ Format #CALL_PAS(121 $DOS_MIF_FILENAME [ $OPTIONS ])  }
{ Returns NULL if file  does not exist }
begin
   rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin { File name }
    if not PLSTR(P2,STR,L,true,SV2) then SV2:=''; { Options }
      INITIALIZE_SCAN_VARIABLES_mif;
      Scaner_mif (1,SV1,SV2,rez,erlist,NULL,0,0);
end;end;


Procedure USE_36(p1,p2,p3:a; var rez:a);
  { Scaner receives data from list of strings,
    numbers and complex structures in the input list are ignored }
  { Format  #CALL_PAS(36 $LIST [$OPTIONS] ) }
begin
   rez:=0;
    if not PLSTR(P2,STR,L,true,SV2) then SV2:=''; { Options }
      INITIALIZE_SCAN_VARIABLES;
      Scaner (2,'',SV2,rez,erlist,p1,0,0);
end;

Procedure USE_37(p1,p2,p3:a; var rez:a);
  { Scaner receives data from absolute address, segment and offset are
    given , and memory is analysed until EOLN EOF EOLN characters;
    First character also must be EOLN;
    This EOLN must appear every 126 bytes or more often. }
  { Format #CALL_PAS(37 $SEGMENT $OFFSET [ $OPTIONS ] )  }
begin
   rez:=0;
    if PLNUM(P1,IM[1]) then
     if PLNUM(P2,IM[2]) then begin
    if not PLSTR(P3,STR,L,true,SV2) then SV2:=''; { Options }
   INITIALIZE_SCAN_VARIABLES;
   Scaner (3,'',SV2,rez,erlist,NULL,IM[1],IM[2]);
end;end;

Procedure USE_38(p1,p2,p3:a; var rez:a);
{ returns error message list,
  produced after last call of "Scaner" }
begin
   rez:=erlist;
end;



Procedure USE_40(p1,p2,p3:a;var rez:a);
 (* ANY -> S-address *)
    begin
        GETS1(rez,x.SA);
        with x.snd^ do begin dtype:=NUMBER;cord:=0;VAL:=P1; end;
    end;


Procedure USE_41(p1,p2,p3:a;var rez:a);
 (* returns current S-address *)
    begin
        GETS1(rez,x.SA);
        with x.snd^ do begin dtype:=NUMBER;cord:=0;VAL:=rez; end;
    end;


Procedure USE_44(p1,p2,p3:a;var rez:a);
  (* sets coordinate to atom *)
  begin rez:=0;
   if not PLNUM(P2,IM[1]) then exit;
   if P1<>0 then begin
        rez:=P1;
        A1:=P1;
        POINTS(A1,x.SA);
        if x.sad^.dtype IN [ATOM..FATOM]-[NUMBER] then x.sad^.cord:=IM[1]
        else if x.snd^.dtype=NUMBER then x.snd^.cord:=IM[1];
        end;
   end;

Procedure USE_45(p1,p2,p3:a;var rez:a);
 begin
 REOPEN(rez,P1);
     { Removes all S-Space saving only this P1 value in result;
       All variables after that moment will have wrong values  }
     { This not allowed in interpreter ! }
 end;

Procedure USE_46(p1,p2,p3:a;var rez:a);
 begin rez:=NULL; end; { Returns null if we are in compiler }

Procedure USE_47(p1,p2,p3:a;var rez:a);
 { Returns ATOM (Expanded form of file specification )
      if file exist }
 {$IFDEF WIN}
 var pch,pchbig:pchar;
 begin
  GetMem(pch,80);
  GetMem(pchbig,80);
  if PLSTR(P1,STR,L,true,SV1) then
     StrPCopy(pch,SV1) else StrCopy(pch,'');
  FileExpand(pchbig,pch);
  rez:=Str_to_textatom(StrPas(pchbig));
  FreeMem(pch,80);
  FreeMem(pchbig,80);
  end;
{$ELSE}
 begin rez:=0;
  if PLSTR(P1,STR,L,true,SV1) then SV1:=Fexpand(SV1)
  else SV1:=Fexpand('');
  rez:=Str_to_textatom(SV1);
 end;
{$ENDIF}

Procedure USE_48(p1,p2,p3:a;var rez:a);
 { The argument if such file exists }
  begin
  rez:=0;
  if PLSTR(P1,STR,L,true,SV1) then
   if ExistFile(SV1) then rez:=p1;
  end;

{*****************************************}
{*****  PLACE FOR USER'S FUNCTIONS *******}
Procedure USE_9(p1,p2,p3:a;var rez:a);begin rez:=0; end;
{$I USECRT.PAS}
{$I USEDDE.PAS}
{$I USEDLL.PAS}
{$I USE132.PAS}

Procedure USE_78(p1,p2,p3:a;var rez:a);
begin
if PLNUM(P1,IM[1]) then max_printlevel:=IM[1];
end;

Procedure USE_79(p1,p2,p3:a;var rez:a);
var is_tree:boolean;AP:PTR;elnum:longint;
label 22;
begin
rez:=NULL;
first(p1,AP);
is_tree:=(AP.PTRTYPE=PTRTREE);
elnum:=0;
while AP.NEL<>0 do begin
    inc(elnum);
    if EqAtoms(AP.cel,p2) then goto 22;
    next(AP);
    end;
exit;
22:
 if is_tree then begin
            GETS1(rez,x.SA);      (* makes S-Address *)
            with x.sad^ do begin  (* fills descriptor *)
            dtype:=IDATOM;NAME:=AP.ARC;
            end; { with }
            end
  else rez:=long_to_atom(elnum);

end;


Procedure USE_91(p1,p2,p3:a;var rez:a);
(* For LISTS - modifies list descriptor and
   makes it 1 element shorter by deleting ladst element ;
   Returns the argument.
   If length of list is 1 or 0 then this function returns NULL,
   but list descriptor is not modified (!!!)
   If argument is not list then returns NULL.

   E.g.
     $A:=(.A.)
     #CALL_PAS(91 $A) returns NULL , but $A retain (.A.)

     $A:=(.A B.)
     #CALL_PAS(91 $A) returns (.A.), and $A is (.A.)
 *)
var is_tree:boolean;AP:PTR;elnum:longint;len:longint;
label 22;
begin
REZ:=NULL;
POINTS(P1,X.sa);
if  X.SMLD^.DTYPE<>LISTMAIN then Exit;
len:= X.SMLD^.TOTALELNUM;
if (len=1) or (len=0) then Exit;
first(p1,AP);
for i:=1 to len-2 do Next(AP);
(* WE are standing on the last element of future list *)
(* The next elements (or descriptor) are to cut off,
   we split to 4 cases main/fragm  element/descriptor *)
REZ:=P1;
POINTS(AP.CURFRAGMENT,X.SA);
if  X.SMLD^.DTYPE=LISTMAIN
  then
   begin
   if AP.NEL=MAINLISTELNUM
     then
       begin X.SMLD^.NEXT:=NULL ;
             X.SMLD^.LASTFRAGM:=AP.CURFRAGMENT;
             (* Correction 8-APR-1993 *)
       end
     else DEC(X.SMLD^.ELNUM);
   DEC(X.SMLD^.TOTALELNUM);
   end
  else
   begin
   if AP.NEL=FRAGMLISTELNUM
     then  begin
             X.SFLD^.NEXT:=NULL;
             POINTS(P1,X.SA);
             X.SMLD^.LASTFRAGM:=AP.CURFRAGMENT;
             (* Correction 8-APR-1993 *)
            end
     else DEC(X.SFLD^.ELNUM);
   POINTS(P1,X.SA);
   DEC(X.SMLD^.TOTALELNUM);
   end;
end;



Function SELECTION(tree,arc:a):a;
var AP:PTR;
begin
 SELECTION:=NULL;
 First(tree,AP);
 if AP.PTRTYPE<>PTRTREE then Exit;
 while (AP.NEL<>NULL)and(AP.ARC<>arc) do Next(AP);
 if AP.ARC=arc then SELECTION:=AP.CEL;
end;

Function INDEXING(list:a;index:longint):a;
var AP:PTR;maxind:longint;
begin
 INDEXING:=NULL;
 First(list,AP);
 if AP.PTRTYPE<>PTRLIST then Exit;
 POINTR(list,X.SA);
 maxind:=X.SMLD^.TOTALELNUM;
 if (index<-maxind)or(index=0)or(index>maxind) then exit;
 if index<0 then index:=maxind+index+1;
 for i:=1 to index-1 do Next(AP);
 INDEXING:=AP.CEL;
end;



Procedure USE_92(p1,p2,p3:a;var rez:a);
(* Traverses list "p1".
    if element is a number then INDEX is applied to "p2"
    if element is an atom the SELECTION ia applied to "p2" *)
var AP:PTR;
begin
REZ:=P2;
First(p1,AP);
if AP.PTRTYPE<>PTRLIST then begin rez:=NULL;Exit;end;
while AP.NEL<>NULL do begin
  POINTR(AP.CEL,X.SA);
  if X.SND^.DTYPE=NUMBER then rez:=INDEXING(rez,X.SND^.VAL)
  else if X.SAD^.DTYPE=IDATOM then rez:=SELECTION(rez,X.SAD^.NAME)
  else rez:=NULL;
  if rez=NULL then Exit;
  Next(AP);
  end;
end;

Procedure USE_93(p1,p2,p3:a;var rez:a);
 begin
 (* returns stack size*)
 rez:=Long_to_atom(Sptr);
 end;





Procedure USE_108(p1,p2,p3:a;var rez:a);
{ Get Environment variable ;
  Requires Variable name(string)
  Returns NULL if absent
   or value (converted to number if possible) }
 {$IFDEF WIN}
 var pc,pc2:pchar;
 {$ENDIF}
 begin
  rez:=0;
 {$IFDEF WIN}
  if PLSTR(P1,STR,L,false,SV1) then
   begin
   GetMem(pc,255);
   GetMem(pc2,255);

   StrPCopy(pc2,STR);
   pc2:=GetEnvVar(pc2);
   if pc2<>nil then
    begin
     StrCopy(pc,pc2);
     rez:=str_to_atom(StrPas(pc));
    end;
 end;
  {$ELSE}
  if PLSTR(P1,STR,L,true,SV1) then
  SV1:=GetEnv(SV1);
  if SV1<>'' then  rez:=str_to_atom(SV1);
  {$ENDIF}
end;



Procedure USE_110(p1,p2,p3:a;var rez:a);
 (* SQRT *)
 begin rez:=0;
    if  PLNUM(P1,IM[1]) then
         rez:=Long_to_atom(trunc(sqrt(IM[1])));
 end;

Procedure USE_111(p1,p2,p3:a;var rez:a);
 (* SQRT(p1*p1+p2*p2) *)
 begin rez:=0;
    if  PLNUM(P1,IM[1]) then
      IF plnum(p2,im[2]) THEN
         rez:=Long_to_atom(trunc(sqrt(iM[1]*im[1]+iM[2]*im[2])));
 end;

Procedure USE_112(p1,p2,p3:a;var rez:a);
 (* SAVES S-CODE TO HANDLE IN GLOBAL MEMORY *)
 (* Returns handle value *)
 var DUMMYFILE:filespecification;
 begin
 rez:=NULL;
 if p1=NULL then Exit;
{$IFDEF WIN}
 DEFPAGE.TMEMFLAG:=true;
 DEFPAGE.SAVES(DUMMYFILE,p1);
 (* WRITES usinng standard SAVES, a little modified *)
 DEFPAGE.TMEMFLAG:=false;
 rez:=long_to_atom(DEFPAGE.TMEMHANDLE);
{$ENDIF}
 end;

Procedure USE_113(p1,p2,p3:a;var rez:a);
 (* LOADS S-CODE FROM HANDLE IN GLOBAL MEMORY and
    INVALIDATES the handle *)
 var DUMMYFILE:filespecification;
 begin
 rez:=NULL;
{$IFDEF WIN}
 if not PLNUM(p1,IM[1]) then Exit;
 if IM[1]=0 then Exit;
 DEFPAGE.TMEMHANDLE:=IM[1];  (* valid handle *)
 DEFPAGE.TMEMFLAG:=true;
 DEFPAGE.LOADS(DUMMYFILE,rez);
  (* READS using standard LOADS,a little modified*)
 DEFPAGE.TMEMFLAG:=false;
{$ENDIF}
 end;


 Procedure USE_114(p1,p2,p3:a; var rez:a);
  { Scaner receives data from global memory chain.
   The global memory handle of the first chain element
   is given. Optional parameters of scanning can be given.
   The handle is stream-memory special handle, can
   be received from GRAD.DLL GetLDT function.
   Format #CALL_PAS(114 $HANDLE [ $OPTIONS ] )  }
begin
   rez:=0;
    if PLNUM(P1,IM[1]) then
    if IM[1]<>0 then
    begin
    if not PLSTR(P2,STR,L,true,SV2) then SV2:=''; { Options }
     INITIALIZE_SCAN_VARIABLES;
      Scaner (4,'',SV2,rez,erlist,NULL,IM[1],0);
    end;
end;

Procedure USE_116(p1,p2,p3:a;var rez:a);
{ Returns C-string value 'a"bc\n' -> '"abc\\m\"' }
 begin
  rez:=0;
  if not PLSTR(P1,STR,L,true,SV1) then exit;
  sv2:='"';
  for i:=1 to L do begin
      if sv1[i] in ['"','\'] then sv2:=sv2+'\';
      sv2:=sv2+sv1[i];
      end;
  sv2:=sv2+'"';
  rez:=str_to_textatom(SV2);
end;

Procedure USE_119(p1,p2,p3:a; var rez:a);
  { Returns amount of available memory for windows }
begin
 {$IFDEF WIN}

   rez:=NULL;
   lconc(rez,long_to_atom(memavail));
   lconc(rez,long_to_atom(GlobalCompact(32000)));
 {$ENDIF}
 end;


{$IFDEF WIN}
 var srec:TSearchrec;
{$ELSE}
 var srec:Searchrec;
{$ENDIF}
Procedure USE_120(p1,p2,p3:a; var rez:a);
 var attr:longint;
     pc:array[0..80]of char;
  { Calls FindFirst (PATH ATTR)
       or FindNext  (),
    returns NULL or ( NAME SIZE TIME ATTR ) }
begin
   rez:=NULL;
    if plstr(P1,STR,L,true,SV2) then begin end;
    if not plnum(P2,attr) then attr:=32;
   if p1<>NULL then
   begin
   {$IFDEF WIN}
   StrPcopy(pc,SV2);
   FindFirst(pc,attr,srec);
   {$ELSE}
   FindFirst(SV2,attr,srec);

   {$ENDIF}
    end
    else FindNext(srec);
     if DosError<>0 then begin rez:=NULL;exit;end;
   {$IFDEF WIN}
     lconc(rez,str_to_textatom(StrPas(srec.name) (* Changed in version 2.41 3-FEB-93 *)
     ));
   {$ELSE}
     lconc(rez,str_to_textatom(srec.name));   (* Changed in version 2.41 3-FEB-93 *)
   {$ENDIF}
     lconc(rez,long_to_atom(srec.size));
     lconc(rez,long_to_atom(srec.time));
     lconc(rez,long_to_atom(srec.attr));

 end;


Procedure USE_122(p1,p2,p3:a; var rez:a);
  { Returns amount of available pages for windows }
var busy_pages,allocated_pages,available_pages:longint;
begin
 {$IFDEF WIN}
   vols(busy_pages,allocated_pages,available_pages);
   rez:=NULL;
   lconc(rez,long_to_atom(busy_pages));
   lconc(rez,long_to_atom(allocated_pages));
   lconc(rez,long_to_atom(available_pages));
  {$ENDIF}
 end;


{$I USE80.PAS}
{$I USERCALL.PAS}



{*****************************************}
begin
  ERLIST:=NULL;
end.
