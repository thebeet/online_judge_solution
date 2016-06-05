{$R-}
type
 hp=array [0..8632] of longint;
var
 hps:array [0..18] of hp;
 i,n,m,l,d:longint;
procedure hp_tj(var hp1:hp);
 var
  i,t:longint;
 begin
  t:=0;
  for i:=1 to hp1[0] do
   begin
    hp1[i]:=hp1[i]+t;
    t:=hp1[i] div 1000;
    hp1[i]:=hp1[i] mod 1000;
   end;
  while (t>0) do
   begin
    inc(hp1[0]);
    hp1[hp1[0]]:=t mod 1000;
    t:=t div 1000;
   end;
 end;
procedure num_hp(var hp1:hp;n:longint);
 begin
  hp1[0]:=1;
  hp1[1]:=n;
  hp_tj(hp1);
 end;
procedure hp_cf_hp(var hp1,hp2,hp3:hp);
 var
  i,j,n,m:longint;
 begin
  for i:=1 to hp1[0] do
   for j:=1 to hp2[0] do
    hp3[i+j-1]:=hp1[i]*hp2[j];
  hp3[0]:=hp1[0]+hp2[0]-1;
  hp_tj(hp3);
 end;
procedure inc_hp(var hp1:hp);
 var
  i:longint;
 begin
  inc(hp1[1]);
  i:=1;
  while (hp1[i]=1000) do
   begin
    hp1[i]:=0;
    inc(hp1[i]);
    inc(i);
   end;
  if (i>hp1[0]) then hp1[0]:=i;
 end;
procedure out(var hp1:hp);
 var
  i:longint;
 begin
  write(hp1[hp1[0]]);
  for i:=(hp1[0]-1) downto 1 do
   begin
    if hp1[i]<10 then write('0');
    if hp1[i]<100 then write('0');
    write(hp1[i]);
   end;
  writeln;
 end;
begin
 readln(n);
 d:=0;
 if n<5 then n:=n div d;
 {fillchar(hps,sizeof(hps),0);}
 num_hp(hps[1],2);
 num_hp(hps[0],1);
 hp_cf_hp(hps[0],hps[1],hps[2]);
 hps[0]:=hps[2];
 inc_hp(hps[2]);
 for i:=3 to n do
  begin
   hp_cf_hp(hps[0],hps[i-1],hps[i]);
   hps[0]:=hps[i];
   inc_hp(hps[i]);
  end;
 for i:=1 to n do
  out(hps[i]);
end.
