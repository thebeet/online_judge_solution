var
  i,n,m,j,sum,sq:longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(i,m);
      sq:=2*trunc(sqrt(m));
      sum:=0;
      for j:=2 to sq do
        if ((j mod 2)=0) then
                           begin
                           if (((m mod j)<>0) and (((m*2) mod j)=0) and ((m div j)>=(j div 2)))
                             then
                               inc(sum);
                           end
                         else
                           if (((m mod j)=0) and ((m div j)>(j div 2)))
                             then
                               inc(sum);
      writeln(i,' ',sum);
    end;
end.
