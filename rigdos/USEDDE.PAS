Procedure USE_73(p1,p2,p3:a;var rez:a); { WINPROLOG }
 { Waits for Initialisation message from DDE }
begin
 {$IFDEF WIN}
  rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin
    if PLSTR(P2,STR,L,true,SV2) then begin
          WinProlog(SV1,SV2);
          WinLoopInit;
    end;end;
 {$ELSE}
 rez:=0;
 writeln('Starting DDE dialog');
 {$ENDIF}
end;

Procedure USE_81(p1,p2,p3:a;var rez:a); { WINPROLOG }
 { Waits for Initialisation message from DDE }
begin
 {$IFDEF WIN}
  rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin
    if PLSTR(P2,STR,L,true,SV2) then begin
          WinProlog(SV1,SV2);
          {WinLoopInitStand;}
    end;end;
 {$ELSE}
 rez:=0;
 writeln('Starting DDE dialog');
 {$ENDIF}
end;




Procedure USE_74(p1,p2,p3:a;var rez:a); { WINGETMES }
begin
    rez:=0;
{$IFDEF WIN}
    SVAR:=WINGETMESS;
{$ELSE}
    WRITE('"DDE>"');
    READLN(SVAR);(* Enters from screen *)
{$ENDIF}
    REZ:=Str_to_atom(SVAR);
 end;

Procedure USE_75(p1,p2,p3:a;var rez:a); {WINANSWER}
  begin
    if PLSTR(P1,STR,L,true,SV1) then
  {$IFDEF WIN}
    WINANSWER(SV1);
  {$ELSE}
 begin
 WRITELN;
 WriteLN('DDE:"',SV1,'"');
 end;
{$ENDIF}
  end;


Procedure USE_82(p1,p2,p3:a;var rez:a);
{ msgbox - SHOWS a message (up to 80 chars) on the screen }
begin
  rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin
    if PLSTR(P2,STR,L,true,SV2) then begin

     {$IFDEF WIN}
      if PLNUM(P3,IM[1]) then IM[2]:=MSGBOX(SV1,SV2,IM[1])
                         else IM[2]:=MSGBOX(SV1,SV2,mb_iconInformation);
 {$ELSE}
   rez:=0;
   writeln('Message: ',SV1,':');
   writeln(SV2);
   Writeln('Press ENTER to continue...');
   readln;
   IM[2]:=1;
 {$ENDIF}
 Gets1(rez,x.sa);
 With x.snd^ do begin dtype:=number;val:=IM[2];end;
 end;end;


end;


Procedure USE_84(p1,p2,p3:a;var rez:a);
 BEGIN
 rez:=0;

{ writeln('S1');}
  if PLNUM(P1,IM[1]) then begin
{ writeln('S2');}
   rez:=0;
    if PLNUM(P2,IM[2]) then
     begin
{ writeln('S3');}
     rez:=0;
 {$IFDEF WIN}

    SETWINCRT(IM[1],IM[2]);
 {$ENDIF}
    end;end;end;


Procedure USE_83(p1,p2,p3:a;var rez:a);
{ input box - SHOWS a message (up to 60 chars) on the screen;
  returns an answer }
begin
  rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin
    if not PLSTR(P2,STR,L,true,SV2) then SV2:=' ';

 {$IFDEF WIN}
      DoInpBox(mainwindow,SV2,SV1);
 {$ELSE}
 rez:=0;
 writeln('INPUT:',SV1);
 writeln('(',SV2,')');
 Writeln('ENTER answer to continue...');
 Readln(SV2);
 {$ENDIF}
  REZ:=Str_TO_Atom(SV2);
 end;
end;


 { German for Windows }
(*upcase_tab[chr(228)]:=chr(196);
  upcase_tab[chr(246)]:=chr(214);
  upcase_tab[chr(252)]:=chr(220);*)


Procedure USE_85(p1,p2,p3:a;var rez:a);
{ UPCASE }
begin
  rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin
      for j:=1 to Length(SV1) do
        case SV1[j] of
        'a'..'z' : SV1[j]:=Chr(Ord(Sv1[j])-32);
        chr(228) : SV1[j]:=chr(196);
        chr(246) : SV1[j]:=chr(214);
        chr(252) : SV1[j]:=chr(220);
        else begin end;
        end;
      rez:=Str_to_textatom(SV1);  (* Changed in version 2.41 3-FEB-93 *)
   end;
end;

Procedure USE_86(p1,p2,p3:a;var rez:a);
{ LOCASE }
begin
  rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin
      for j:=1 to Length(SV1) do
       case SV1[j]of
         'A'..'Z': SV1[j]:=Chr(Ord(Sv1[j])+32);
        chr(196) : SV1[j]:=chr(228);
        chr(214) : SV1[j]:=chr(246);
        chr(220) : SV1[j]:=chr(252);
        else begin end;
        end;
      rez:=Str_to_textatom(SV1);   (* Changed in version 2.41 3-FEB-93 *)
   end;
end;

Procedure USE_87(p1,p2,p3:a;var rez:a);
{ SUBSTR }
begin
  rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin
      if PLNUM(P2,IM[1]) then
         if not PLNUM(P3,IM[2]) then IM[2]:=L;
      rez:=Str_to_textatom(COPY(SV1,IM[1],IM[2]));  (* Changed in version 2.41 3-FEB-93 *)
   end;
end;

Procedure USE_88(p1,p2,p3:a;var rez:a);
{ INDEX }
begin
  rez:=0;
   if PLSTR(P1,STR,L,true,SV1) then begin
     if PLSTR(P2,STR,L,true,SV2) then
       rez:=Long_to_atom(Pos(SV1,SV2));
   end;
end;

Procedure USE_89(p1,p2,p3:a;var rez:a);
{ GET DATE and TIME }

var  aw:array[1..4]of word;

begin
   rez:=0;
   Getdate(aw[1],aw[2],aw[3],aw[4]);
   for i:=1 to 4 do Lconc(rez,Long_to_atom(aw[i]));
   Gettime(aw[1],aw[2],aw[3],aw[4]);
   for i:=1 to 4 do Lconc(rez,Long_to_atom(aw[i]));
end;

Procedure USE_90(p1,p2,p3:a;var rez:a);
  VAR
    III: INTEGER;
    HLT:integer;
  BEGIN
    if not PLNUM(P1,IM[2]) then IM[2]:=105;
    if PLNUM(P2,IM[1]) then HLT:=IM[1] ELSE HLT:=0;
    FOR III := 1 TO FILENUM DO
      IF FILETAB[III].ISOPEN and not FILETAB[III].SCREEN  THEN
        BEGIN
        WRITELN(FILES[III]);
        CLOSE(FILES[III]);
        END;
    If OUT_OPEN then Close(Out);
    CLOSEA;CLOSES;
  {$IFDEF WIN}
   SendMessage(hwnd(-1),wm_user+IM[2],0,0);
   Donewincrt;
  {$ENDIF}
  HALT(HLT);
  END;

