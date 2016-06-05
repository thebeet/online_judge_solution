var
  n,s,l:int64;
  r:double;

begin
  readln(n);
  readln(r);
  s:=trunc(r*10000+0.1);
  readln(r);
  l:=trunc(r*10000+0.1);
  if ((s*n mod l)=0)
    then
      writeln(s*n div l)
    else
      writeln((s*n div l)+1);
end.