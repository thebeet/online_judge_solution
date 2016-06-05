var
 p,q:real;
 i,n,m,a:longint;
begin
 a:=0;
 n:=3;
 readln(p,q);
 if p>q then p:=n div a;
 for i:=1 to 2000000 do
  begin
   n:=trunc(i*p/100-0.0000001);
   m:=trunc(i*q/100-0.0000001);
   if m>n then break;
  end;
 writeln(i);

end.
