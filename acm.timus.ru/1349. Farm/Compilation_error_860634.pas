var
  n:longint;
begin
  readln(n);
  if (n=1) then writeln('1 2 3');
  if (n=2) then writeln('3 4 5');
  if (n<>1) and (n<>2) then writeln('-1');
end;
