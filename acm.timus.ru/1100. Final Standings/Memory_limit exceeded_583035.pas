type
 team=record
       id:longint;
       pn:byte;
      end;
var
 i,n,j:longint;
 ss:array [0..150000] of team;
begin
 fillchar(ss,sizeof(ss),0);
 read(n);
 for i:=1 to n do
  read(ss[i].id,ss[i].pn);
 for j:=100 downto 1 do
  for i:=1 to n do
   if (ss[i].pn=j) then writeln(ss[i].id,' ',j);
end.