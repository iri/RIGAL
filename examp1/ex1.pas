
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
   otherwise   writeln (a);end;end;  
 BEGIN WITH STATE DO BEGIN  
  w:=1;v:=1;x:=1;y:=1;z:=1;  
Z := 1 ; 
X :=  PLUS(  Z , 1 ) ; 
Y := 1 ; 
 WHILE   LESS(  Y ,  PLUS(  X , 1 ) ) =tt DO BEGIN  
Z :=  PLUS(  Z , Z ) ; 
Y :=  PLUS(  Y , 1 ) ; 
END; 
 IF   LESS(  Y ,  PLUS(  X , 1 ) )  =err THEN x:=err;  
V :=  PLUS(  1 , 1 ) ; 
V :=  PLUS(   PLUS(  V , V ) , V ) ; 
W := 1 ; 
Writeln (' Post-DUMP : '); 
Write ('w=');Val(w); 
Write ('v=');Val(v); 
Write ('x=');Val(x); 
Write ('y=');Val(y); 
Write ('z=');Val(z); 
readln;end;  
END. 
