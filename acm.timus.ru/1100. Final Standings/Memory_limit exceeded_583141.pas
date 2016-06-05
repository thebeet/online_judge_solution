type
 team=record
       id:longint;
       pn:byte;
      end;
var
 i,n,j,id,m:longint;
 ss:array [0..100,0..50000] of longint;
begin
 read(n);
 for i:=1 to n do
  begin
   read(id,m);
   inc(ss[m,0]);
   ss[m,ss[m,0]]:=id;
  end;
 for j:=100 downto 0 do
  for i:=1 to ss[j,0] do
   writeln(ss[j,i],' ',j);
end.
