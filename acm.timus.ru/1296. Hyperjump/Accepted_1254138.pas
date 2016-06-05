var
  i,n,m,s,ans:longint;

begin
  readln(n);
  ans:=0;
  s:=0;
  for i:=1 to n do
    begin
      readln(m);
      if ((ans+m)>0) then ans:=ans+m else ans:=0;
      if s<ans then s:=ans;
    end;
  writeln(s);
end.

