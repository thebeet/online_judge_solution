const
 pf1:array [0..40] of longint=(0,3,4,5,6,7,8,8,9,9,10,12,12,12,12,14,15,15,15,16,16,18,20,20,21,21,24,24,24,24,27,28,30,30,32,35,36,36,40,40,48);
 pf2:array [0..40] of longint=(0,4,3,12,8,24,6,15,12,40,24,5,9,16,35,48,8,20,36,12,30,24,15,21,20,28,7,10,18,32,36,21,16,40,24,12,15,27,9,30,14);
var
 y,x,i,n,m,t:longint;
 map:array [0..50,0..50] of boolean;
 ch:char;
procedure change(x,y,dx,dy:longint);
 begin
  if (((x+dx)<=m) and ((y+dy)<=n))
   then
    map[x+dx,y+dy]:=not map[x+dx,y+dy];
  if (((x+dx)<=m) and ((y-dy)>0))
   then
    map[x+dx,y-dy]:=not map[x+dx,y-dy];
  if (((x-dx)>0) and ((y+dy)<=n))
   then
    map[x-dx,y+dy]:=not map[x-dx,y+dy];
  if (((x-dx)>0) and ((y-dy)>0))
   then
    map[x-dx,y-dy]:=not map[x-dx,y-dy];
 end;
begin
 fillchar(map,sizeof(map),false);
 readln(M,N);
 for x:=1 to m do
  begin
   for y:=1 to n do
    begin
     read(ch);
     if (ch='B') then map[x,y]:=true;
 