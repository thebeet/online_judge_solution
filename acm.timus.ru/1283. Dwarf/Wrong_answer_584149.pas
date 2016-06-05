var
 k:longint;
 n,m,p:real;
begin
 read(n,m,p);
 k:=0;
 while (n>=m) do
  begin
   inc(k);
   n:=n*(100-p)/100;
  end;
 writeln(k);
end.
