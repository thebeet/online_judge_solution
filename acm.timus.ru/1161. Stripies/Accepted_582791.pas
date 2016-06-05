var
 i,n,j:longint;
 t:real;
 aa:array [0..100] of real;
begin
 read(n);
 for i:=1 to n do
  read(aa[i]);
 for i:=1 to n do
  for j:=(i+1) to n do
   if (aa[i]>aa[j]) then begin t:=aa[i];aa[i]:=aa[j];aa[j]:=t;end;
 for i:=(n-1) downto 1 do
  aa[i]:=2*sqrt(aa[i]*aa[i+1]);
 writeln(aa[1]:0:2);
end.
