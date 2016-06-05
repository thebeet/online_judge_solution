var
 p,q:real;
 i,n:longint;
begin
 readln(p,q);
 for i:=1 to 20000 do
  if ((trunc(i*q/100)-trunc(i*p/100))>1)
   then
    break;
 writeln(trunc(i*q/100));
end.