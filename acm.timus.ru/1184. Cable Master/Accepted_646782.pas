const max = 10000;

var a :array[1..max] of longint;

n,k :word;

dau,cuoi,giua,
kq :longint;

ok :boolean;


procedure nhap;
var i :word;
x :real;
begin
readln( n, k);

for i := 1 to n do
begin readln( x);
a[i] := round( x * 100);
end;
end;


procedure cut;
var doan :longint;
i :word;
begin
doan := 0;
for i := 1 to n do
begin
doan := doan + a[i] div giua ;
if doan >= k then break;
end;

ok := ( doan >= k );
if ok and ( giua > kq ) then kq := giua;
end;


procedure solve;
begin
dau := 1; cuoi := 10000000; kq := 0;

repeat
giua := ( dau + cuoi ) div 2;

cut;

if ok then dau := giua + 1
else cuoi := giua - 1;
until dau > cuoi;
end;


procedure out;
var x :real;
begin
x := kq;
x := x / 100;
writeln(x :0 :2);
end;


begin
nhap;
solve;
out;
end.
