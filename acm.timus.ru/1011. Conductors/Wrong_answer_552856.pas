var
 p,q:real;
 i,n,m:longint;
begin
 readln(p,q);
 for i:=1 to 2000000 do
  begin
   n:=trunc(i*p/100-0.00001);
   m:=trunc(i*q/100-0.00001);
   if m>n then break;
  end;
 writeln(i);

end.
