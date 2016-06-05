var
 s,i,a,b:longint;
begin
 read(a,b);
 s:=0;
 for i:=a to b do
  if ((i mod 2)=1) then inc(s);
 writeln(s);
end.