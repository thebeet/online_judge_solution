var
 i:array [0..4,0..4] of longint;
 map,map1:array [0..5,0..5] of boolean;
 ch:char;
 x,y,aa:longint;
 flag:boolean;
begin
 for x:=1 to 4 do
  begin
   for y:=1 to 4 do
    begin
     read(ch);
     if ch='b' then map[x,y]:=true else map[x,y]:=false;
    end;
   readln;
  end;
 map1:=map;
 for i[1,1]:=0 to 1 do
 for i[1,2]:=0 to 1 do
 for i[1,3]:=0 to 1 do
 for i[1,4]:=0 to 1 do
 for i[2,1]:=0 to 1 do
 for i[2,2]:=0 to 1 do
 for i[2,3]:=0 to 1 do
 for i[2,4]:=0 to 1 do
 for i[3,1]:=0 to 1 do
 for i[3,2]:=0 to 1 do
 for i[3,3]:=0 to 1 do
 for i[3,4]:=0 to 1 do
 for i[4,1]:=0 to 1 do
 for i[4,2]:=0 to 1 do
 for i[4,3]:=0 to 1 do
 for i[4,4]:=0 to 1 do
  begin
   map:=map1;
   for x:=1 to 4 do
    for y:=1 to 4 do
     if (i[x,y]=1)
      then
       begin
        map[x,y]:=not map[x,y];
        map[x+1,y]:=not map[x+1,y];
        map[x,y+1]:=not map[x,y+1];
        map[x-1,y]:=not map[x-1,y];
        map[x,y-1]:=not map[x,y-1];
       end;
   flag:=true;
   for x:=1 to 4 do
    for y:=1 to 4 do
     if (map[x,y]=false) then begin flag:=false;break;end;
   aa:=0;
   if flag
    then
     begin
      for x:=1 to 4 do
       for y:=1 to 4 do
        if (i[x,y]=1) then inc(aa);
      writeln(aa);
      exit;
     end;
  end;
 writeln('Impossible');
end.