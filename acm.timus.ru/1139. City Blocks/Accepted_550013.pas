var
 n,i,m,x,y,b,s,t,t1:longint;
 nn:int64;
 k:real;
begin
 nn:=0;
 readln(n,m);
 dec(n);dec(m);
 k:=n/m;
 t1:=0;t:=0;
 for i:=1 to m do
  begin
   t:=trunc(i*n/m-0.0000001);
   nn:=nn+t-t1+1;
   t1:=trunc(i*n/m);
  end;
 writeln(nn);
end.
