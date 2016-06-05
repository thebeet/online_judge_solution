type
 hp=array [0..10000] of longint;
var
 i,n,m,j,l,k,t:longint;
 hp1,hp2,ans,hp3:hp;
procedure read_hp(var ans:hp);
 var
  i,ln,t:longint;
  ch:char;
 begin
  ln:=0;
  while (not eof) do
   begin
    read(ch);
    if (ord(ch)>40)
     then
      begin
       inc(ln);
       ans[ln]:=(ord(ch)-48) mod 10;
      end;
   end;
  ans[0]:=ln;
  for i:=1 to (ln shr 1) do
   begin
    t:=ans[i];
    ans[i]:=ans[ln-i+1];
    ans[ln-i+1]:=t;
   end;
 end;
procedure hp_add_hp(var hp1,hp2,ans:hp);
 var
  i,ln,t:longint;
 begin
  t:=0;
  if hp1[0]>hp2[0] then ln:=hp1[0] else ln:=hp2[0];
  for i:=1 to ln do
   begin
    ans[i]:=hp1[i]+hp2[i]+t;
    t:=ans[i] div 10;
    ans[i]:=ans[i] mod 10;
   end;
  if t>0 then begin inc(ln);ans[ln]:=t;end;
  ans[0]:=ln;
 end;
procedure hp_cf_hp(var hp1,hp2,ans:hp;f:longint);
 var
  i,l,k,j,n,t:longint;
 begin
  fillchar(ans,sizeof(ans),0);
  for i:=f to hp1[0] do
   for j:=f to hp2[0] do
    ans[i+j-1]:=ans[i+j-1]+hp2[j]*hp1[i];
  t:=0;
  for k:=(f+f-1) to (hp1[0]+hp2[0]-1) do
   begin
    ans[k]:=ans[k]+t;
    t:=ans[k] div 10;
    ans[k]:=ans[k] mod 10;
   end;
  while (t>0) do
   begin
    inc(k);
    ans[k]:=t mod 10;
    t:=t div 10;
   end;
  ans[0]:=k;
 end;
function hp_max_hp(var hp1,hp2:hp):longint;
 var
  i:longint;
 begin
  if (hp1[0]>hp2[0]) then begin hp_max_hp:=1;exit;end;
  if (hp1[0]<hp2[0]) then begin hp_max_hp:=-1;exit;end;
  for i:=hp1[0] downto 1 do
   begin
    if (hp1[i]>hp2[i]) then begin hp_max_hp:=1;exit;end;
    if (hp1[i]<hp2[i]) then begin hp_max_hp:=-1;exit;end;
   end;
  hp_max_hp:=0;
 end;
procedure out(var hp1:hp);
 var
  i:longint;
 begin
  for i:=hp1[0] downto 1 do
   write(hp1[i]);
  writeln;
 end;
begin
 read_hp(hp1);
 hp_add_hp(hp1,hp1,hp3);
 fillchar(hp1,sizeof(hp1),0);
 hp1[0]:=(hp3[0]+1) shr 1;
 for i:=hp1[0] downto 1 do
  begin
   for j:=1 to 9 do
    begin
     hp1[i]:=j;
     hp_cf_hp(hp1,hp1,hp2,i);
     t:=hp_max_hp(hp2,hp3);
     if t=0 then begin out(hp1);exit;end;
     if t=1 then begin dec(j);break;end;
    end;
   hp1[i]:=j;
  end;
 out(hp1);
end.