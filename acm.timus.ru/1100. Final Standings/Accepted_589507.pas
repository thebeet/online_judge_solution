var
 i,n,j,id,m:longint;
 ss:array [1..150000] of longint;
begin
 read(n);
 i:=1;
 while (i<=n) do
  begin
   read(id,m);
   if (m<100)
    then
     begin
      ss[i]:=m*10000000+id-1;
     end
    else
     begin
      writeln(id,' 100');
      dec(i);
      dec(n);
     end;
   inc(i);
  end;
 for j:=99 downto 0 do
  for i:=1 to n do
   if ((ss[i] div 10000000)=j)
    then
     writeln((ss[i] mod 10000000)+1,' ',j);
end.
