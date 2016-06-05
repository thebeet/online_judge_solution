var
 i,j,h,n,t:longint;
 pf:array [0..250] of longint;
begin
 for i:=1 to 250 do
  pf[i]:=i*i;
 read(n);
 for i:=1 to trunc(sqrt(n)) do
  if pf[i]=n then begin writeln('1');exit;end;
 for i:=1 to trunc(sqrt(n)) do
  for j:=1 to trunc(sqrt(n-pf[i])) do
   if pf[i]+pf[j]=n then begin writeln('2');exit;end;
 for i:=1 to trunc(sqrt(n)) do
  for j:=1 to trunc(sqrt(n-pf[i])) do
   for h:=1 to trunc(sqrt(n-pf[i]-pf[j])) do
    if pf[i]+pf[j]+pf[h]=n then begin writeln('3');exit;end;
 writeln('4');
end.