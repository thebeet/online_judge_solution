var
 i,n,m:longint;
 f:array [0..10000] of longint;
function g(x,y:longint):longint;
 var
  i:longint;
  a:array [0..5] of longint;
 begin
  a[0]:=1;
  for i:=1 to 5 do
   a[i]:=(a[i-1]*x) mod 9973;
  g:=((((y-1)*a[5]+a[3]-x*y+3*x+7*y) mod 9973)+9973) mod 9973;
 end;
begin
 read(n);
 f[0]:=0;
 for i:=1 to 9973 do
  f[i]:=g(i,f[i-1]);
 m:=n mod 9973;
 if m=0 then m:=m+9973;
 if n=0 then writeln('0') else writeln(f[m]);
end.
