type
 map=array [0..9,0..9] of longint;
var
 tm:map;
 i,n,m,k,l:longint;
procedure init(m:longint);
 var
  x,y,i,j,ans:longint;
 begin
  for x:=1 to m do
   for y:=1 to m do
    begin
     ans:=0;
     if (((x-1)>0) and ((y-2)>0)) then inc(ans);
     if (((x-1)>0) and ((y+2)<=m)) then inc(ans);
     if (((x-2)>0) and ((y-1)>0)) then inc(ans);
     if (((x-2)>0) and ((y+1)<=m)) then inc(ans);
     if (((x+1)<=m) and ((y-2)>0)) then inc(ans);
     if (((x+1)<=m) and ((y+2)<=m)) then inc(ans);
     if (((x+2)<=m) and ((y-1)>0)) then inc(ans);
     if (((x+2)<=m) and ((y+1)<=m)) then inc(ans);
     tm[x,y]:=ans;
    end;
 end;
procedure out(mm:map);
 var
  i,x,y:longint;
 begin
  for i:=1 to (m*m) do
   begin
    for x:=1 to m do
     for y:=1 to m do
      if mm[x,y]=-i
       then
         writeln(chr(ord('a')+x-1),y);
   end;
 end;
procedure dfs(x,y,s:longint;mm:map);
 var
  i,n,mn,px,py:longint;
  gone:array [0..8] of boolean;
 begin
  fillchar(gone,sizeof(gone),true);
  inc(s);
  mm[x,y]:=-s;
  if s=m*m then begin out(mm);halt;end;
  while true do
   begin
    mn:=10;
     if (gone[1] and ((x-1)>0) and ((y-2)>0) and (mm[x-1,y-2]>0) and (mn>mm[x-1,y-2])) then begin mn:=mm[x-1,y-2];px:=x-1;py:=y-2;gone[1]:=false;end;
     if (gone[2] and ((x-1)>0) and ((y+2)<=m) and (mm[x-1,y+2]>0) and (mn>mm[x-1,y+2])) then begin mn:=mm[x-1,y+2];px:=x-1;py:=y+2;gone[2]:=false;end;
     if (gone[3] and ((x-2)>0) and ((y-1)>0) and (mm[x-2,y-1]>0) and (mn>mm[x-2,y-1])) then begin mn:=mm[x-2,y-1];px:=x-2;py:=y-1;gone[3]:=false;end;
     if (gone[4] and ((x-2)>0) and ((y+1)<=m) and (mm[x-2,y+1]>0) and (mn>mm[x-2,y+1])) then begin mn:=mm[x-2,y+1];px:=x-2;py:=y+1;gone[4]:=false;end;
     if (gone[5] and ((x+1)<=m) and ((y-2)>0) and (mm[x+1,y-2]>0) and (mn>mm[x+1,y-2])) then begin mn:=mm[x+1,y-2];px:=x+1;py:=y-2;gone[5]:=false;end;
     if (gone[6] and ((x+1)<=m) and ((y+2)<=m) and (mm[x+1,y+2]>0) and (mn>mm[x+1,y+2])) then begin mn:=mm[x+1,y+2];px:=x+1;py:=y+2;gone[6]:=false;end;
     if (gone[7] and ((x+2)<=m) and ((y-1)>0) and (mm[x+2,y-1]>0) and (mn>mm[x+2,y-1])) then begin mn:=mm[x+2,y-1];px:=x+2;py:=y-1;gone[7]:=false;end;
     if (gone[8] and ((x+2)<=m) and ((y+1)<=m) and (mm[x+2,y+1]>0) and (mn>mm[x+2,y+1])) then begin mn:=mm[x+2,y+1];px:=x+2;py:=y+1;gone[8]:=false;end;
    if mn=10 then break;
    dfs(px,py,s,mm);
   end;
 end;
begin
 read(m);
 if m=1 then begin writeln('a1');exit;end;
 if m<5 then begin writeln('IMPOSSIBLE');exit;end;
 init(m);
 dfs(1,1,0,tm);
end.


