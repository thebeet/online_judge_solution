var
 n,m,s:longint;
 ch:char;
begin
 s:=1;
 read(n);
 m:=0;
 while (not eof(input)) do
  begin
   read(ch);
   if (ch='!') then inc(m);
  end;
 while (n>0) do
  begin
   s:=s*n;
   n:=n-m;
  end;
 writeln(s);
end.