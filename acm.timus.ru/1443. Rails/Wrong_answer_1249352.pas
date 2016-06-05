var
  n,s,l:int64;
  r:double;

begin
  readln(n);
  readln(r);
  s:=trunc(r*10000+0.1);
  readln(r);
  l:=trunc(r*10000+0.1);
  writeln(((s*n*10-1) div (l*10))+1);
end.