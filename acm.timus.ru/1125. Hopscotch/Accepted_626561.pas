const
 dx:array [0..52] of longint=(0,3,4,5,6,7,8,8,9,9,10,12,12,12,12,14,15,15,15,16,16,18,20,20,20,21,21,24,24,24,24,24,27,28,28,30,30,32,33,35,36,36,36,40,40,40,42,44,45,45,48,48,48);
 dy:array [0..52] of longint=(0,4,3,12,8,24,6,15,12,40,24,5,9,16,35,48,8,20,36,12,30,24,15,21,48,20,28,7,10,18,32,45,36,21,45,16,40,24,44,12,15,27,48,9,30,42,40,33,24,28,14,20,36);
var
 y,x,i,n,m,t:longint;
 map:array [-60..110,-60..110] of boolean;
 ch:char;
procedure change(x,y,dx,dy:longint);
 begin
   map[x+dx,y+dy]:=not map[x+dx,y+dy];
   map[x+dx,y-dy]:=not map[x+dx,y-dy];
   map[x-dx,y+dy]:=not map[x-dx,y+dy];
   map[x-dx,y-dy]:=not map[x-dx,y-dy];
 end;
begin
 fillchar(map,sizeof(map),false);
 readln(m,n);
 for x:=1 to m do
  begin
   for y:=1 to n do
    begin
     read(ch);
     if (ch='B') then map[x,y]:=true;
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
       for i:=1 to 52 do
        change(x,y,dx[i],dy[i]);
      end;
   end;
 for x:=1 to m do
  begin
   for y:=1 to n do
    if map[x,y] then write('B') else write('W');
   writeln;
  end;
 close(output);
end.
