{$N+}
program boxes;
var
n,a,b:integer;
p:array[0..20,0..15,0..15]of extended;
procedure init;
var
i,j:integer;
begin
readln(n,a,b);
fillchar(p,sizeof(p),0);
for i:=0 to a do
for j:=0 to b do
p[0,i,j]:=1;
end;
procedure solve(n,a,b:integer);
var
i,j:integer;
s:longint;
begin
if n>=1 then
for i:=0 to a do
for j:=0 to b do
begin
if p[n-1,i,j]=0 then
solve(n-1,i,j);
p[n,a,b]:=p[n,a,b]+p[n-1,i,j];
end;
end;
begin
init;
solve(n,a,b);
writeln(p[n,a,b]:0:0);
end.
