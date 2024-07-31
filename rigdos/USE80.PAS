
{ FLOATING POINT PROCESSOR }
Procedure USE_80(p1,p2,p3:a;var rez:a);


type ref_real=^real;
const real_size=sizeof(real);
type real_string=array[1..real_size]of char;
var i:integer; re1,re2,re3:real;
     c1,c2:char;X:MPD;
    the_a,the_D:longint;
label 1;


 begin
 (********** ALL the operations should end with
     [ Forms REZ ] Goto 1
      or
     Forms RE1
  **********************************************)

 rez:=0; { in case of unsuccessful data returns NULL }
 if not PLSTR(P1,STR,L,FALSE,SV1) then goto 1;
 c1:=STR[1];if L=2 then c2:=STR[2] else c2:=' ';

  (*********************** first argument (p2) is not real ************)
 case c1 of (*1*)
  'S':begin  { String -> real }
    if not PLSTR(P2,STR,L,TRUE,SV1) then goto 1;
    system.VAL(SV1,re1,i);
    if i<>0 then goto 1;
    end;
  'I':begin  { Integer -> real }
    if not PLNUM(p2,IM[2]) then goto 1;
    re1:=IM[2]; { *1.0 }
    end;
{$IFDEF xSUN}
           OTHERWISE
{$ELSE}
           ELSE
{$ENDIF}
     { Real -> ... }
   begin  (*2*)
   if not PLSTR(P2,STR,L,FALSE,SV1) then goto 1;
  (* if L<>real_size then goto 1; *)
   re2:=ref_real(Addr(str[1]))^;

  (*********************** first argument (p2) is real (re2) ************)

   case c1 of  (*3*)

   'D':begin { Added in 2.21 29-JUN-92 }
       { Digit number before and after the dot in
         decimal numbers }
       rez:=NULL;
       if L=real_size then goto 1;
       lconc(rez,long_to_atom(ord(str[real_size+1])));
       lconc(rez,long_to_atom(ord(str[real_size+2])));
       goto 1;
       end;
   'T': begin
       if (re2<-2147483648.999)or(re2>2147483647.999) then goto 1;
       if (re2<-2147483647.999) then IM[3]:=-maxlongint-1
       (* to prevent TRUNC error ! *)
       else IM[3]:=Trunc(re2);
       Gets1(rez,X.sa);
       with x.snd^ do begin dtype:=number;val:=IM[3];end;
       goto 1;
       end;
   'Z': begin
       if not PLNUM(p3,IM[2]) then goto 1;
            (* A*100+D , D maybe negative *)
       the_A:=IM[2] div 100;
       the_D:=IM[2] mod 100;
       if the_D>50 then begin the_D:=the_D-100;Inc(the_A);end;
       SVAR:=REAL_TO_STRING_F(re2,the_A,the_D);
       i:=length(SVAR);
       PutAtm(SVAR[1],I,ATM);
       Gets1(rez,x.sa);
       with x.sad^ do begin Dtype:=atom;name:=atm;end;
       goto 1;
       end;
   'R': begin    (* (67.7689 2) -> 6776.89,-0.89 -> 6776.000 -> 67.760000 *)
        if not PLNUM(p3,IM[2]) then goto 1;
        for i:=1 to IM[2] do 
            begin
            if abs(re2)>1E+37 then goto 1; (* To prevent float overflow *)
            re2:=re2*10.0;
            end;
        if Frac(re2)>0.5 then re2:=re2+1;
        if Frac(re2)<-0.5 then re2:=re2-1;
        re2:=re2-Frac(re2);
        for i:=1 to IM[2] do re2:=re2/10.0;
        re1:=re2;
        end;
   'V': begin
       system.str(re2,SVAR);
       while SVAR[1]=' ' do delete(svar,1,1);
       i:=length(SVAR);

       PutAtm(SVAR[1],I,ATM);
       Gets1(rez,x.sa);
       with x.sad^ do begin Dtype:=atom;name:=atm;end;
       goto 1;

        end;
   'Q':if re2>=0 then re1:=sqrt(re2) else goto 1;
   'X':if abs(re2)<87 then re1:=exp(re2) else goto 1;
   'L':if re2>0  then re1:=ln(re2) else goto 1;
{$IFDEF xSUN}
           OTHERWISE
{$ELSE}
           ELSE
{$ENDIF}

 (*********************** second argument (p3) is also real (re3) ************)

    begin  (*4*)
       if not PLSTR(P3,STR,L,false,SV1) then goto 1;
       re3:=ref_real(Addr(str[1]))^;
       case c1 of  (*5*)
       '+': begin
            if (re2<>0)and(re3<>0) then
             if (ln(abs(re2))>87)or(ln(abs(re3))>87)then goto 1;
            re1:=re2+re3;
            end;
       '-': begin
            if (re2<>0)and(re3<>0) then
             if (ln(abs(re2))>87)or(ln(abs(re3))>87)then goto 1;
            re1:=re2-re3;
            end;
       '*':
           begin
           if (re2<>0)and(re3<>0) then
             if abs(  (ln(abs(re2)))+ (ln(abs(re3))) )>87  then goto 1;
           re1:=re2*re3;
           end;
       '/':if re3<>0 then 
             begin
             if (re2<>0)and(re3<>0) then
              if abs(  (ln(abs(re2)))- (ln(abs(re3))) )>87 then goto 1;
             re1:=re2/re3;
             end
           else goto 1;
       '=':begin  if re2=re3  then rez:=p2; goto 1; end;
       '>':begin  if c2='=' then begin if re2>=re3  then rez:=p2 ; end
                  else           begin if re2> re3  then rez:=p2 ; end;
                  goto 1;end;
       '<':begin
            if c2='=' then begin if re2<=re3  then rez:=p2 ; end
        else if c2='>' then begin if re2<>re3  then rez:=p2 ; end
            else           if re2<re3   then rez:=p2 ;
            goto 1;end;
{$IFDEF xSUN}
           OTHERWISE
{$ELSE}
           ELSE
{$ENDIF}
       goto 1;  { Wrong real operation }
      end; (*5*)
    end; (*4*)
   end; (*3*)
  end; (*2*)
 end; (*1*)
 { This part processes only + - * / S(str->real) I(int->real) }
 ref_real(addr(SVAR[1]))^:=re1;
 ;
 PutAtm(SVAR[1],real_size,ATM);
 Gets1(rez,x.sa);
 with x.sad^ do begin dtype:=fatom; name:=atm;end;
1:
end;




