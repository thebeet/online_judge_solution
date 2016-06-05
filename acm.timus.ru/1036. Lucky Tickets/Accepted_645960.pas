program lucky;
const
maxn=200;
type
arraytype=array[0..maxn]of integer;
var
p:array[0..1,0..500]of arraytype;
b:arraytype;
len:array[0..1,0..500]of integer;
n,m,i:integer;
procedure init;
var
i,j:integer;
begin
readln(n,m);
if odd(m) then
begin
writeln('0');
halt;
end;
m:=m div 2;
fillchar(p,sizeof(p),0);
for i:=0 to m do
for j:=0 to 1 do
len[j,i]:=1;
p[0,0,1]:=1;
end;
procedure add(x,y:integer);
var
l,i:integer;
begin
if len[1,x]>len[0,y] then
l:=len[1,x]
else
l:=len[0,y];
for i:=1 to l do
begin
p[1,x][i]:=p[1,x][i]+p[0,y][i];
p[1,x][i+1]:=p[1,x][i+1]+p[1,x][i] div 10;
p[1,x][i]:=p[1,x][i] mod 10;
end;
while p[1,x][l+1]<>0 do
begin
inc(l);
p[1,x][l+1]:=p[1,x][l] div 10;
p[1,x][l]:=p[1,x][l] mod 10;
end;
len[1,x]:=l;
end;
procedure solve;
var
i,j,k,jj:integer;
begin
for i:=1 to n do
begin
for j:=0 to m do
for k:=0 to 9 do
if (j+k<=m) and (j+k<>0) then
add(j+k,j);
p[0]:=p[1];
p[0,0,1]:=1;
len[0]:=len[1];
len[0,1]:=1;
fillchar(p[1],sizeof(p[1]),0);
end;
end;
procedure square;
var
i,j:integer;
begin
fillchar(b,sizeof(b),0);
for i:=1 to len[0,m] do
for j:=1 to len[0,m] do
begin
b[i+j-1]:=b[i+j-1]+p[0,m,i]*p[0,m,j];
b[i+j]:=b[i+j]+b[i+j-1] div 10;
b[i+j-1]:=b[i+j-1] mod 10;
end;
len[0,m]:=2*len[0,m]-1;
while b[len[0,m]+1]<>0 do
begin
inc(len[0,m]);
b[len[0,m]+1]:=b[len[0,m]] div 10;
b[len[0,m]]:=b[len[0,m]] mod 10;
end;
for i:=len[0,m] downto 1 do
write(b[i]);
writeln;
end;
begin
init;
solve;
square;
end.
