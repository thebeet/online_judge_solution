var
 c,d,i,n,p:longint;
 m1,m,b,a:int64;
begin
 read(n);
 read(a);
 m:=-2000000000;
 p:=4;
 d:=0;
 for i:=2 to n do
  begin
   read(b);
   m1:=b-a;
   if (m1>m) then begin m:=m1;p:=i;end;
   a:=b;
  end;
 writeln(p-1,' ',p);
end.


