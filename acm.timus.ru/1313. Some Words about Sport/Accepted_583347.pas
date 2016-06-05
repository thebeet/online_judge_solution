var
 n,i,j,t,k:longint;
 map:array [0..100,0..100] of longint;
 ans:array [0..10000] of longint;
begin
 read(n);
 for i:=1 to n do
  for j:=1 to n do
   read(map[i,j]);
 k:=0;
 for i:=1 to n do
  for j:=1 to i do
   begin
    inc(k);
    ans[k]:=map[i-j+1,j];
   end;
 for i:=(n+1) to (2*n-1) do
  begin
   t:=n*2-i;
    for j:=1 to t do
     begin
      inc(k);
      ans[k]:=map[n-j+1,i+j-n];
     end;
  end;
 for i:=1 to k do
  writeln(ans[i]);
end.
