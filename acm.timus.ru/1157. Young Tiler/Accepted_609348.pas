var
 i,n,m,t,s,k,p:longint;
 f:array [0..10000] of longint;
function ss(m:longint):longint;
 var
  i,s,y:longint;
 begin
  s:=1;
  y:=trunc(sqrt(m));
  for i:=2 to y do
   if ((m mod i)=0) then inc(s);
  ss:=s;
 end;
begin
 read(m,n,k);
 t:=1;
 for i:=1 to 10000 do
  f[i]:=ss(i);
 for i:=1 to 10000 do
  if (((i-k)>0) and (f[i]=n) and (f[i-k]=m)) then begin writeln(i);exit;end;
 writeln('0');
end.