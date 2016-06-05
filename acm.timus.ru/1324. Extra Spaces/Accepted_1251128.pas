var
  i,n,m,j:longint;
  p,ans:array [0..100] of longint;

begin
  ans[1]:=2;
  p[1]:=2;
  ans[2]:=2;
  p[2]:=3;
  for i:=3 to 8 do
    begin
      p[i]:=ans[i-1]*ans[i-1]+ans[i-1]-1;
      ans[i]:=(p[i]+1) shr 1;
    end;
  readln(n);
  for i:=1 to 8 do
    if (p[i]>n) then
      begin
        writeln(i-1);
        for j:=(i-1) downto 1 do
          writeln(ans[j]);
        exit;
      end;
end.
end.

