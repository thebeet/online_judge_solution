var
 n:longint;
begin
 read(n);
 n:=n mod 8;
 case n of
  1:writeln('1');
  2:writeln('1');
  3:writeln('2');
  4:writeln('0');
  5:writeln('2');
  6:writeln('1');
  7:writeln('2');
  0:writeln('0');
 end;
end.
