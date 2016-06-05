var
 a,b,c,d,i,n,m,p,m1:longint;
begin
 read(a);
 m:=-1;
 p:=1;
 d:=0;
 if n=1 then n:=n div d;
 while not eof(input) do
  begin
   read(b);
   inc(p);
   m1:=abs(a-b);
   if (m1>m) then begin m:=m1;p:=i;end;
  end;
 writeln(p-1,' ',p);
end.

