type
 hp=array [0..10000] of longint;
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
 hp1[0]:=2;
 hp1[1]:=6;
 hp1[2]:=3;
 read(n);
 for i:=1 to (n-1) do
  cc(hp1,55);
 for i:=hp1[0] downto 1 do
  writeln(hp1[i]);
end.