var
 i,j,s,n:longint;
begin
 read(n);
 for i:=1 to (n-1) do
  write('(');
 for i:=1 to n do
  begin
   write('sin(1');
   for j:=2 to i do
    begin
     if ((j mod 2)=1) then write('+') else write('-');
     write('sin(',j);
    end;
   for j:=1 to i do
    write(')');
   write('+',n-i+1);
   if i<>n then write(')');
  end;
 writeln;
end.
