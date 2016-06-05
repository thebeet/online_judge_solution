const
 dx:array [0..40] of longint=(0,3,4,5,6,7,8,8,9,9,10,12,12,12,12,14,15,15,15,16,16,18,20,20,21,21,24,24,24,24,27,28,30,30,32,
 35,36,36,40,40,48);
 dy:array [0..40] of longint=(0,4,3,12,8,24,6,15,12,40,24,5,9,16,35,48,8,20,36,12,30,24,15,21,20,28,7,10,18,32,36,21,16,40,24,
 12,15,27,9,30,14);
var
 y,x,i,n,m,t,d,x1,y1:longint;
 map:array [0..51,0..51] of boolean;
 ch:char;
procedure change(x,y,dx,dy:longint);
 var
  s,t,x2,y2:longint;
 begin
  x2:=abs(x-dx);y2:=abs(y-dy);
  s:=x2*x2+y2*y2;
  t:=trunc(sqrt(s));t:=t*t;
  if (s<>t) then exit;
  map[dx,dy]:=not map[dx,dy];
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
       for x1:=1 to m do
        for y1:=1 to n do
          change(x,y,x1,y1);
   end;
 for x:=1 to m do
  begin
   for y:=1 to n do
    if map[x,y] then write('B') else write('W');
   writeln;
  end;
end.
