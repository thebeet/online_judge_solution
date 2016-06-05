const nn=150001;
type rec=record
id:longint;
m:byte;
end;
var a:array[1..nn] of rec;
j,i,n:longint;

begin
readln(n);
for i:=1 to n do
readln(a[i].id,a[i].m);
for j:=100 downto 0 do
for i:=1 to n do
if a[i].m=j then writeln(a[i].id,' ',a[i].m);
end. 