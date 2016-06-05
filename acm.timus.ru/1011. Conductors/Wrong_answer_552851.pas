var
 p,q:real;
 i,n:longint;
begin
 readln(p,q);
 for i:=1 to 2000000 do
  if (trunc(i*p/100-0.0000001)+1)<(trunc(i*q/100-0.0000001)+1)
   then
    break;
  writeln(i);
end.