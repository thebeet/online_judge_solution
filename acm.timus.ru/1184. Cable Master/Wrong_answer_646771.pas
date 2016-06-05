var
 i,n,m,l,ss,bb,nn:longint;
 ls:array [0..10000] of longint;
 ll:real;
function check(l:longint):boolean;
 var
  i,s:longint;
 begin
  s:=0;
  for i:=1 to n do
   s:=s+ls[i] div l;
  if s>=m then check:=true else check:=false;
 end;
begin
 read(n,m);
 for i:=1 to n do
  begin
   read(ll);
   ls[i]:=trunc(ll*100);
  end;
 if (not check(1)) then begin writeln('0.00');exit;end;
 ss:=1;
 bb:=1000000001;
 while ((bb-ss)>1) do
  begin
   nn:=(ss+bb) shr 1;
   if check(nn) then ss:=nn else bb:=nn;
  end;
 ll:=ss/100;
 writeln(ll:0:2);
end.




