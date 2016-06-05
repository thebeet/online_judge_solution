var
  n,s,l:longint;
  r:double;

begin
  readln(n);
  readln(r);
  s:=trunc(r*10000+0.1);
  readln(r);
  l:=trunc(r*10000+0.1);
  writeln(((s*n-1) div l)+1)
end.
