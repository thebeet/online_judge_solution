type
 team=record
       id:longint;
       pn:byte;
      end;
var
 i,n,j,id,m:longint;
 ss:array [0..150000] of team;
begin
 read(n);
 i:=1;
 while (i<=n) do
  begin
   read(id,m);
   if (m<100)
    then
     begin
      ss[i].id:=id;
      ss[i].pn:=m;
     end
    else
     begin
      writeln(id,' 100');
      dec(i);
      dec(n);
     end;
   inc(i);
  end;
 for j:=99 downto 0 do
  for i:=1 to n do
   if (ss[i].pn=j)
    then
     writeln(ss[i].id,' ',j);
end.
