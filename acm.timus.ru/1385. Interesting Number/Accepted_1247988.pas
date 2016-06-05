var
  i,n:longint;

begin
  readln(n);
  if n=1 then write('14');
  if n=2 then write('155');
  if n>2 then write('1575');
  for i:=4 to n do write('0');
  writeln;
end.