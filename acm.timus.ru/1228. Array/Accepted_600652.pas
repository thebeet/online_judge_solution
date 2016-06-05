var
 k:array[1..20]of longint;
 d:array[0..20]of longint;
 i,s,n:longint;
begin
 readln(n,s);
 for i:=1 to n do
  readln(d[i]);
 d[0]:=s;
 k[n]:=d[n-1]-1;
 for i:=n-1 downto 1 do
  k[i]:=(d[i-1] div d[i])-1;
 for i:=1 to n-1 do
  write(k[i],' ');
 writeln(k[n]);
end.
