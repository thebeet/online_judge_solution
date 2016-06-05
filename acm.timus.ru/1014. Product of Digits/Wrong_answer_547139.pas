var
 n,i,nt,k:longint;
 bb:array [0..10000] of integer;
begin
 fillchar(bb,sizeof(bb),0);
 readln(n);
 nt:=n;
 k:=0;
 for i:=2 to 7 do
  if ((n mod i)=0) then begin n:=n div i;dec(i);end;
 if (n=1)
  then
   begin
    for i:=9 downto 2 do
     if ((nt mod i)=0) then
     begin
      nt:=nt div i;
      inc(k);
      bb[k]:=i;
      inc(i);
     end;
    for i:=k downto 1 do
     write(bb[i]);
   end
   else write('-1');
  writeln;
 end.