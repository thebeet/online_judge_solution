var
 n,i,maxp:longint;
 m,t,p,p1:int64;
begin
 read(n);
 read(t);
 p1:=-2000000000*1000000;
 for i:=2 to n do
  begin
   read(m);
   p:=m-t;
   if p>p1 then begin p1:=p;maxp:=i;end;
   t:=m;
  end;
 writeln(maxp-1,' ',maxp);
end.
