var
  a,b,c:int64;

begin
  readln(a,b,c);
  a:=1 shl ((c-1) div a);
  b:=1 shl ((c-1) div b);
  writeln(a);
  writeln(b);
  writeln('2');
end.