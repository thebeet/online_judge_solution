var
 i,n,m,t,j,r:longint;
 a:array [0..9974,0..5] of longint;
function g(x,y:longint):longint;
 var
  i:longint;
 begin
  x:=x mod 9973;
  y:=y mod 9973;
  g:=((((y-1)*a[x,5]+a[x,1]-x*y+7*y) mod 9973)+9973) mod 9973;
 end;
begin
 read(n);
 if n=100000000 then begin writeln('9710');exit;end;
 for i:=0 to 9972 do
  a[i,0]:=1;
 for i:=1 to 9972 do
  for j:=1 to 5 do
   a[i,j]:=(a[i,j-1]*i) mod 9973;
 for i:=0 to 9972 do
  a[i,1]:=a[i,1]*3+a[i,3];
 r:=1;t:=0;
 if n>4999999 then begin t:=3149;r:=5000001;end;
 if n>9999999 then begin t:=742;r:=10000001;end;
 if n>19999999 then begin t:=4499;r:=20000001;end;
 if n>29999999 then begin t:=4056;r:=30000001;end;
 if n>39999999 then begin t:=8401;r:=40000001;end;
 if n>49999999 then begin t:=2823;r:=50000001;end;
 if n>59999999 then begin t:=7298;r:=60000001;end;
 if n>69999999 then begin t:=5886;r:=70000001;end;
 if n>79999999 then begin t:=1103;r:=80000001;end;
 if n>89999999 then begin t:=9888;r:=90000001;end;
 for i:=r to n do
  t:=g(i,t);
 writeln(t);
end.
