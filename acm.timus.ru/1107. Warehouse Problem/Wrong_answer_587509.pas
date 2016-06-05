var
 i,k,t:longint;
begin
 readln(i,k,t);
 writeln('YES');
 for i:=1 to k do
 begin
  readln(t);
  writeln(2-(t mod 2));
 end;
end.
