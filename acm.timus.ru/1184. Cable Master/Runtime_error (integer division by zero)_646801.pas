var
 i,n,m,ss,bb,nn,d:longint;
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
   ls[i]:=round(ll*100);
  end;
 if (not check(1)) then begin writeln('0.00');exit;end;
 ss:=99;
 bb:=100000001;
 while (bb<ss) do
  begin
   nn:=(ss+bb) div 2;
   if check(nn) then ss:=nn+1 else bb:=nn-1;
  end;
 d:=0;
 ss:=ss-1;
 if ss<100 then ss:=ss div d;
 write(ss div 100,'.');
 if ((ss mod 100)<10) then write('0');
 writeln(ss mod 100);
end.




