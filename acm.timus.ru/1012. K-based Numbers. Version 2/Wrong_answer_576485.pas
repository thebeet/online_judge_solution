type
 hp=array [0..1000] of longint;
var
 i,n,m,t,k:longint;
 m0,m1,m2:hp;
procedure add_hp(var hp1,hp2,ans:hp);
 var
  i,l,t:longint;
 begin
  if hp1[0]>hp2[0] then l:=hp1[0] else l:=hp2[0];
  t:=0;
  for i:=1 to l do
   begin
    ans[i]:=hp1[i]+hp2[i]+t;
    t:=ans[i] div 10;
    ans[i]:=ans[i] mod 10;
   end;
  if t>0 then begin ans[0]:=l+1;ans[l+1]:=t;end
         else ans[0]:=l;
 end;
procedure cf_hp(var hp1:hp;num1:longint);
 var
  i,t:longint;
 begin
  t:=0;
  for i:=1 to hp1[0] do
   begin
    hp1[i]:=hp1[i]*num1+t;
    t:=hp1[i] div 10;
    hp1[i]:=hp1[i] mod 10;
   end;
  if (t>0) then begin inc(hp1[0]);hp1[i+1]:=t;end;
 end;
begin
 read(n,k);
 m0[0]:=0;
 m0[1]:=1;
 m1[0]:=1;
 m1[1]:=k-1;
 add_hp(m0,m1,m2);
 cf_hp(m2,k-1);
 for i:=3 to n do
  begin
   m0:=m1;
   m1:=m2;
   add_hp(m0,m1,m2);
   cf_hp(m2,k-1);
  end;
 for i:=m2[0] downto 1 do
  write(m2[i]);
 writeln;
end.