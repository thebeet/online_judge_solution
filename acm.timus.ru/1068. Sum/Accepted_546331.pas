var
 i,n,m:longint;
begin
 readln(n);
 m:=0;
 if (n>=1)
  then
   for i:=1 to n do
    m:=m+i
  else
   for i:=1 downto n do
    m:=m+i;
 writeln(m);
end.