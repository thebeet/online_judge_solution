var
  n,s,l:longint;
  r:double;

begin
  readln(n);
  readln(r);
  s:=trunc(r*10000+0.1);
  readln(r);
  l:=trunc(r*10000+0.1);
  if ((s mod l)=0)
    then
      writeln((s div l)*n)
    else
      writeln((s*n div l)+1);
end.