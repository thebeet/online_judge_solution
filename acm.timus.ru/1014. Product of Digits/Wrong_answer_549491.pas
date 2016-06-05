var
 n,i,k,t:longint;
 bb:array [0..100] of longint;
begin
 fillchar(bb,sizeof(bb),0);
 readln(n);
 t:=0;
 k:=0;
 if (n>10) then begin
 for i:=9 downto 2 do
  if ((n mod i)=0) then
   begin
    n:=n div i;
    inc(k);
    bb[k]:=i;
    inc(i);
   end;
  if (n=1)
   then
    for i:=k downto 1 do
     write(bb[i])
   else write('-1');
  writeln;
  end
  else
  writeln(n);
 end.
