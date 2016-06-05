type
 hp=array [0..100000] of longint;
var
 i,n:longint;
 hp1:hp;
procedure cc(var hp1:hp;n:longint);
 var
  i,t:longint;
 begin
  t:=0;
  for i:=1 to hp1[0] do
   begin
    hp1[i]:=hp1[i]*n+t;
    t:=hp1[i] div 10;
    hp1[i]:=hp1[i] mod 10;
   end;
  if ((t>0) and (t<10)) then begin hp1[0]:=hp1[0]+1;hp1[hp1[0]]:=t;end;
  if (t>9) then begin hp1[0]:=hp1[0]+2;hp1[hp1[0]]:=t div 10;hp1[hp1[0]-1]:=t mod 10;end;
 end;
begin
 read(n);
 hp1[0]:=1;
 hp1[1]:=1;
 if (n<5)
  then
   writeln(n)
  else
   begin
    while (n>0) do
     if (n>4) then begin cc(hp1,3);n:=n-3;end
               else begin cc(hp1,n);n:=0;end;
    for i:=hp1[0] downto 1 do
     write(hp1[i]);
    writeln;
   end;
end.