var
 i,j,n,m:longint;
 v:array [0..150] of longint;
begin
 read(n);
 for i:=1 to n do
  read(v[i]);
 for i:=1 to n do
  for j:=(i+1) to n do
   if v[i]>v[j] then
    begin m:=v[i];v[i]:=v[j];v[j]:=m;end;
 m:=0;
 for i:=1 to ((n+1) div 2) do
  m:=m+(v[i]+1) div 2;
 writeln(m);
end.
