const
 maxn=10000;
var
c:array [1..maxn] of longint;
ans,n,s,i,high,j:longint;

begin
read(n,s);

fillchar(c,sizeof(c),0);
c[s]:=1;
for i:=s to n-1 do
if c[i]>0 then
begin
if n>i+i then high:=i+i else high:=n;
for j:=i+1 to high do
if (c[i]+1>c[j]) and (j*100 mod i=0)
then c[j]:=c[i]+1;
end;

ans:=0;
for i:=s to n do
if c[i]>ans then ans:=c[i];
writeln(ans);
end.
