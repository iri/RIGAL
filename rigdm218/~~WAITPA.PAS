Program Wait;
uses Crt;
label 99;
var i,j,k,X,Y,TA:integer; s:string[5];c,c1:char;
begin
Randomize;
X:=WhereX; Y:=WhereY; TA:=TextAttr;
s:=ParamStr(1);
Val(s,i,j);
s:=ParamStr(2);
if s='' then j:=100 else Val(s,j,k);
i:=i*j;
i:=i-300;
Window(1,1,80,25);
GotoXY(20,25);
TextAttr:=74;
    Write('Press any key to suspend execution or ESC to exit');

for k:=1 to (i div 100) do begin
  Delay(100);
  if keypressed then
    begin
    GotoXY(20,25);
    write('   Press  ENTER  to  continue  or  ESC  to  exit ');
    repeat
       c:=Readkey;
       if c=#0 then c1:=Readkey; 
    until ((c=#27) or (c=#13));
    if c=#27 then halt(3);
    goto 99;
    end;
 end;
if i>10000 then
  begin  Sound(500);Delay(100);Nosound;Delay(2000);end;

99:

GotoXY(X,Y);
TextAttr:=TA;
Sound(400+Random(600));
Delay(100);
Sound(400+Random(600));
Delay(100);
Sound(400+Random(600));
Delay(100);
Nosound;

end.
