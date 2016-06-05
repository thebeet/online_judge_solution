const
 dx:array [0..40] of longint=(0,3,4,5,6,7,8,8,9,9,10,12,12,12,12,14,15,15,15,16,16,18,20,20,21,21,24,24,24,24,27,28,30,30,32,
 35,36,36,40,40,48);
 dy:array [0..40] of longint=(0,4,3,12,8,24,6,15,12,40,24,5,9,16,35,48,8,20,36,12,30,24,15,21,20,28,7,10,18,32,36,21,16,40,24,
 12,15,27,9,30,14);
var
 y,x,i,n,m,t,d:longint;
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
 d:=0;
 readln(m,n);
 for x:=1 to m do
  begin
   for y:=1 to n do
    begin
     read(ch);
     if (ch='B') then map[x,y]:=true;
     if ((ch<>'B') and (ch<>'W')) then n:=n div d;
    end;
   readln;
  end;
 for x:=1 to m do
  for y:=1 to n do
   begin
    read(t);
    if ((t mod 2)=1)
     then
      begin
       for i:=1 to n do
        map[x,i]:=not map[x,i];
       for i:=1 to m do
        map[i,y]:=not map[i,y];
       map[x,y]:=not map[x,y];
       for i:=1 to 40 do
        change(x,y,dx[i],dy[i]);
      end;
   end;
 for x:=1 to m do
  begin
   for y:=1 to n do
    if map[x,y] then write('B') else write('W');
   writeln;
  end;
end.
