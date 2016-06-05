var
 i,j,k,n,m,s:longint;
 map:array [0..40,0..40] of char;
 q:array [0..40,0..40,1..4] of boolean;
 ch:char;
procedure floodfill(i,j:longint);
 begin
  if (map[i,j+1]='.')
   then
    begin
    map[i,j+1]:='G';
    floodfill(i,j+1);
    end
   else
    if map[i,j+1]='#' then q[i,j,1]:=true;
  if (map[i,j-1]='.')
   then
    begin
    map[i,j-1]:='G';
    floodfill(i,j-1);
    end
   else
    if map[i,j-1]='#' then q[i,j,3]:=true;
  if (map[i-1,j]='.')
   then
    begin
    map[i-1,j]:='G';
    floodfill(i-1,j);
    end
   else
    if map[i-1,j]='#' then q[i,j,4]:=true;
  if (map[i+1,j]='.')
   then
    begin
    map[i+1,j]:='G';
    floodfill(i+1,j);
    end
   else
    if map[i+1,j]='#' then q[i,j,2]:=true;
 end;
begin
 readln(n);
 fillchar(q,sizeof(q),false);
 fillchar(map,sizeof(map),'#');
 for i:=1 to n do
  begin
   for j:=1 to n do
    read(map[i,j]);
   readln;
  end;
 map[1,1]:='G';
 floodfill(1,1);
 s:=0;
 for k:=1 to 4 do
  for i:=1 to n do
   for j:=1 to n do
    if q[i,j,k] then inc(s);
 s:=(s-4)*9;
 writeln(s);
end.
