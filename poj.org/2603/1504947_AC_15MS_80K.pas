var
 i,n,j,t,sum:longint;
 num1:array [0..10000] of longint;
begin
 for i:=1 to 10 do
  begin
   read(n);
   for j:=2 to n do
    if ((n mod j)=0) then begin inc(num1[j]);n:=n div j;dec(j);end;
  end;
 sum:=1;
 for i:=2 to 10000 do
  begin
   inc(num1[i]);
   sum:=(sum*num1[i]) mod 10;
  end;
 writeln(sum);
end.