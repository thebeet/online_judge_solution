var
 i,n,p:longint;
 m1,m,b,a:comp;
begin
 read(n);
 read(a);
 m:=-100000;
 p:=2;
 for i:=2 to n do
  begin
   read(b);
   m1:=b-a;
   m1:=abs(m1);
   writeln(m1);
   if (m1>m) then begin m:=m1;p:=i;end;
   a:=b;
  end;
 writeln(p-1,' ',p);
end.



