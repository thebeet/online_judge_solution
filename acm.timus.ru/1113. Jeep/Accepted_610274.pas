var
 a,m,n:longint;
 d,o,w:double;
begin
 read(n,m);
 a:=0;
 w:=0;
 o:=0;
 repeat
  inc(a);
  d:=m/(a*2-1);
  if w+d>=n then break;
  w:=w+d;
  o:=o+m;
 until false;
 d:=n-w;
 o:=o+d*(a*2-1);
 writeln(round(o+0.49999999999));
end.
