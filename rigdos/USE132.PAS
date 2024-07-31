Procedure USE_132(p1,p2,p3:a;var rez:a); {ACCESS LIBRARY FUNCTION}
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
 var ms:string[110];
     pc:pchar;
     qq:mpd;
 begin
 pointr(p2,qq.sa);
 case code of
 1000: ms:='  #CALL_PAS(76) was not called';
 1001: ms:='  1st paramter(handle) is not number';
 1002: ms:='  2nd paramter(function name) is not atom';
 1003: ms:='  handle is less than 32, Library was not opened for access';
 1004: ms:='  no memory 80 bytes';
 1005: ms:='  parameters are not formed in list,possible atom instead of list';
 1006: ms:='  function '+AA_Str(qq.sad^.name)+' not found in library ';
 1008: ms:='  descriptor too small  (see P_max_size in RIF.PAS )';
 1009: ms:='  too many parameters   (see P_max_cnt  in RIF.PAS )';
 1010: ms:='  wrong atoms in list of atoms which must represent super long string (only  non numeric atoms allowed)';
 1011: ms:='   wromg element (tree) in parameters';
 end;
 GetMem(pc,120);
 StrPCopy(pc,ms);
 MessageBox(0,pc,'Internal error in #CALL_PAS(132..) call',16);
 writeln(out,pc);
 pout(p1);
 pout(p2);
 pout(p3);
 FreeMem(pc,120);
 rez:=Long_to_atom(code);
 end;



var handle:Thandle; { library handle }
    pch:pchar;      { function name  }

type tfun=procedure(AP1,AP2:Pointer);

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
    afar:=GetProcAddress(handle,pch);
    afun:=Tfun(afar);
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
  afun(AP1,AP2); { LIBRARY PROCEDURE NAME }
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


 

