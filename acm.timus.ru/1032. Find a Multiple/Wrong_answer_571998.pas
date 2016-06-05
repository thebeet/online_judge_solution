program a1032;
var mas,a:array[0..10001] of integer;
i,j,n:integer;
s:longint;
begin
for i:=0 to 10001 do
mas[i]:=0;
readln(n);
s:=0;
for i:=1 to n do
begin
readln(a[i]);
s:=(s+a[i]) mod n;
if s=0 then
begin
writeln(i);
for j:=1 to i do
writeln(a[j]);
halt;
end;
if mas[s]<>0 then
begin
writeln(i-j-1);
for j:=mas[s]+1 to i do
writeln(a[j]);
halt;
end;
mas[s]:=i;
end;
writeln(0);
end. 