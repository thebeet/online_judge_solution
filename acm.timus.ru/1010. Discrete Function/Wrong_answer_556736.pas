var
 a,b,c,d,i,n,m,p,m1:longint;
begin
 read(n);
 read(a);
 m:=-1;
 p:=1;
 d:=0;
 for i:=2 to n do
  begin
   read(b);
   m1:=abs(a-b);
   if (m1>m) then begin m:=m1;p:=i;end;
   a:=b;
  end;
 writeln(p-1,' ',p);
end.

