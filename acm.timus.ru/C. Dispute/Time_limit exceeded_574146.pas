var
 i,n,m,t,j:longint;
 a:array [0..9974,0..5] of longint;
function g(x,y:longint):longint;
 var
  i:longint;
 begin
  x:=x mod 9973;
  y:=y mod 9973;
  g:=((((y-1)*a[x,5]+a[x,3]-x*y+3*x+7*y) mod 9973)+9973) mod 9973;
 end;
begin
 for i:=0 to 9972 do
  a[i,0]:=1;
 for i:=1 to 9972 do
  for j:=1 to 5 do
   a[i,j]:=(a[i,j-1]*i) mod 9973;
 read(n);
 t:=0;
 for i:=1 to n do
  t:=g(i,t);
 writeln(t);
end.
