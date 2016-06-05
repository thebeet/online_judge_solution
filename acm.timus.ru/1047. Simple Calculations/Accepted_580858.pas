var
 n,i:longint;
 t,a0,ak,s:real;
begin
 read(n);
 read(a0,ak);
 s:=a0*n+ak;
 for i:=n downto 1 do
  begin
   read(t);
   s:=s-i*2*t;
  end;
 s:=s/(n+1);
 writeln(s:0:2);
end.
