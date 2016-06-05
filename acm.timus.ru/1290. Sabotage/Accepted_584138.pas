var
 i,n,k,h:longint;
 num,j:array [0..25000] of integer;
begin
 read(n);
 for i:=1 to n do
  begin
   read(num[i]);
   inc(j[num[i]]);
  end;
 k:=0;
 for i:=0 to 25000 do
  for h:=1 to j[i] do
   begin
    inc(k);
    num[k]:=i;
   end;
 for i:=n downto 1 do
  writeln(num[i]);
end.
