var
 map:array [0..100,0..100] of longint;
 i,n,m,j,tj,k:longint;
begin
 read(n);
 k:=0;
 for i:=1 to n do
  for j:=1 to i do
    begin
     inc(k);
     map[n-i+j,j]:=k;
    end;
 for i:=(n+1) to (2*n-1) do
  begin
   tj:=n*2-i;
    for j:=1 to tj do
     begin
      inc(k);
      map[j,n+j-tj]:=k;
     end;
  end;
 for j:=1 to n do
  begin
   write(map[1,j]);
   for i:=2 to n do
    write(' ',map[i,j]);
   writeln;
  end;
end.