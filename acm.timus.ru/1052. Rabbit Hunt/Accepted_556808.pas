type
 rabbit=record
         x,y:longint;
        end;
var
 ra:array [0..200] of rabbit;
 line:array [0..200,0..200] of integer;
 i,j,h,n,m,a,b:longint;
begin
 read(n);
 for i:=1 to n do
  read(ra[i].x,ra[i].y);
 for i:=1 to n do
  for j:=1 to n do
   begin
    if (i<>j)
     then
      begin
       a:=ra[i].x-ra[j].x;
       b:=ra[i].y-ra[j].y;
       for h:=1 to n do
        if (a*(ra[i].y-ra[h].y)=b*(ra[i].x-ra[h].x))
         then
          inc(line[i,j]);
      end;
   end;
 m:=1;
 for i:=1 to n do
  for j:=1 to n do
   if (line[i,j]>m) then m:=line[i,j];
 writeln(m);
{DEBUG}
{
for i:=1 to n do
  begin
   for j:=1 to n do
    write(line[i,j],' ');
   writeln;
  end;
}
end.