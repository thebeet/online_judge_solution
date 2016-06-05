var
 n,i,m,p,maxp:longint;
 r,max:real;
begin
 max:=-2000000000;
 read(n);
 read(p);
 for i:=2 to n do
  begin
   read(m);
   r:=(m-p)/(i-1);
   if r>max then begin max:=r;maxp:=i;end;
  end;
 writeln('1 ',maxp);
end.