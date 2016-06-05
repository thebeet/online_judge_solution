var
  p:array[0..1001] of longint;
  i,n,m:longint;
  a:double;
begin
  readln(n);
  fillchar(p,sizeof(p),0);
  for i:=1 to n do
    begin
      read(p[i]);
      p[i]:=p[i-1]+p[i];
    end;
  a:=p[n]/n;
  writeln(a:0:6);
end.
  