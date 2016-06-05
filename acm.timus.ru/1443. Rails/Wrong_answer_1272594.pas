var
  n,s,l,t,i,pp:longint;
  r:double;

begin
  readln(n);
  readln(r);
  s:=trunc(r*10000+0.1);
  readln(r);
  l:=trunc(r*10000+0.1);
  t:=(s div l)*n;
  s:=s mod l;
  pp:=l;
  for i:=1 to n do
    begin
      pp:=pp-s;
      if (pp<s)
        then
          begin
            inc(t);
            pp:=s;
          end;
    end;
  writeln(t);

end.
