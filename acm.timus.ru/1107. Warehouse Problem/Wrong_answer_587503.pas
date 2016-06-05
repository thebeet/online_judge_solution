var
 i,n,m,k,s,j,w,t,h:longint;
begin
 read(n,k,m);
 writeln('YES');
 for i:=1 to k do
  begin
   read(h);
   s:=0;
   for j:=1 to h do
    begin
     read(t);
     s:=((s+t) mod (n+1))+1;
    end;
   writeln(s);
  end;
end.