var
  n,m,i,j:longint;
  ns:array [0..1000] of longint;
begin
  readln(n,m);
  for i:=1 to n do
    readln(ns[i]);
  ns[0]:=ns[n];
  for i:=1 to 10 do
    write(ns[(m+i) mod n]);
  writeln;
end.