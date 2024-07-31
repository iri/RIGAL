
 Program Main; 
 const tt=101;ff=102;err=103; 
 var state:record w,v,x,y,z:integer end; 
 function PLUS (a,b:integer) :integer; 
 begin if (a>100) or (b>100) then Plus:=err  
       else if a+b >100 then Plus:=err  
            else Plus:=a+b; end;  
 function LESS (a,b:integer) :integer; 
 begin if (a>100) or (b>100) then Less:=err  
       else if a<b then Less:=tt  
            else Less:=ff; end;  
 Procedure Val(a:integer); 
  begin case a of  
   101 : writeln ('tt');  
   102 : writeln ('ff');  
   103 : writeln ('err');  
   else  writeln (a);end;end;  
 BEGIN WITH STATE DO BEGIN  
  w:=1;v:=1;x:=1;y:=1;z:=1;  
z := 1 ; 
x :=  PLUS(  z , 1 ) ; 
y := 1 ; 
 WHILE   LESS(  y ,  PLUS(  x , 1 ) ) =tt DO BEGIN  
z :=  PLUS(  z , z ) ; 
y :=  PLUS(  y , 1 ) ; 
END; 
 IF   LESS(  y ,  PLUS(  x , 1 ) )  =err THEN x:=err;  
v :=  PLUS(  1 , 1 ) ; 
v :=  PLUS(   PLUS(  v , v ) , v ) ; 
w := 1 ; 
Writeln (' Post-DUMP : '); 
Write ('w=');Val(w); 
Write ('v=');Val(v); 
Write ('x=');Val(x); 
Write ('y=');Val(y); 
Write ('z=');Val(z); 
readln;end;  
END. 
