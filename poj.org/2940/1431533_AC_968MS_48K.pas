var
  i,n:longint;
  l,s,p:int64;

begin
  read(n);
  while (n>0) do
  begin
  p:=0;
  s:=0;
  for i:=1 to n do
    begin
      read(l);
      p:=p+l;
      s:=s+abs(p);
    end;
  writeln(s);
  read(n);
  end;
end.
