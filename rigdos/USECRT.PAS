{ #CALL_PAS  :::: 18 22-29  32-34}



Procedure USE_32(p1,p2,p3:a;var rez:a);
 begin rez:=0;
 if KeyPressed then begin
        Gets1(rez,x.sa);
        with x.snd^ do begin
          dtype:=NUMBER; val:=1;
          end;
     end;
  end;

Procedure USE_33(p1,p2,p3:a;var rez:a);
 begin Gets1(rez,x.sa);
      with x.snd^ do begin
       dtype:=NUMBER; val:=WhereX; end;end;
Procedure USE_34(p1,p2,p3:a;var rez:a);
 begin Gets1(rez,x.sa);
      with x.snd^ do begin
       dtype:=NUMBER; val:=WhereY; end;end;

Procedure USE_22(p1,p2,p3:a;var rez:a);
begin rez:=0;
{$IFNDEF WIN}
if PLNUM(P1,IM[1]) then Delay(IM[1]);
{$ENDIF}
end;

Procedure USE_23(p1,p2,p3:a;var rez:a);
begin rez:=0;
{$IFNDEF WIN}
if PLNUM(P1,IM[1]) then Sound(IM[1]);
{$ENDIF}
end;

Procedure USE_24(p1,p2,p3:a;var rez:a);
begin rez:=0;
{$IFNDEF WIN}
Nosound;
{$ENDIF}
end;

Procedure USE_25(p1,p2,p3:a;var rez:a);

 (* GOTOXY *)
 begin
  rez:=0;
  if PLNUM(P1,IM[1]) then begin
    if PLNUM(P2,IM[2]) then GOTOXY(IM[1],IM[2]);end;end;



Procedure USE_26(p1,p2,p3:a;var rez:a);
 (* WINdoW *)
 begin rez:=0;
 {$IFNDEF WIN}
       if PLNUM(P1,IM[1]) then begin
       if PLNUM(P2,IM[2]) then
        Window (IM[1] mod 80,IM[1] div 80,
                IM[2] mod 80,IM[2] div 80);end;
 {$ENDIF}
 end;

Procedure USE_27(p1,p2,p3:a;var rez:a);
begin rez:=0;
{$IFNDEF WIN}
 (* COLOR ATTR *)
    if PLNUM(P1,IM[1]) then TextAttr:=IM[1];
{$ENDIF}
 end;


Procedure USE_28(p1,p2,p3:a;var rez:a);
begin
rez:=0; CLREOL;end;

Procedure USE_29(p1,p2,p3:a;var rez:a);
begin rez:=0;
 CLRSCR; end;

Procedure USE_18(p1,p2,p3:a;var rez:a);
 (* READKEY *)
    begin
     rez:=0;
     C:=READKEY;
     IM[1]:=ORD(C);
     if C=#00 then begin C:=READKEY;IM[1]:=ORD(C);IM[1]:=IM[1]+256;end;
     GETS1(rez,x.SA);
       with x.snd^ do begin dtype:=NUMBER;cord:=0;VAL:=IM[1];
     end;
    end;
