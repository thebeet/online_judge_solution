var
  a,b,c:longint;

begin
  readln(a,b,c);
  a:=1 shl ((c-1) div a);
  b:=1 shl ((c-1) div b);
  writeln(a,' ',b,' ',2);
end.
