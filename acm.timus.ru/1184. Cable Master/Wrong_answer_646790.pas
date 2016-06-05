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
 ss:=1;
 bb:=2000000001;
 while ((bb-ss)>1) do
  begin
   nn:=(ss+bb) div 2;
   if check(nn) then ss:=nn else bb:=nn;
  end;
 d:=0;
 {for i:=ss to bb do
  if (not check(i)) then begin ss:=i-1;break;end;}
 if ss<100 then ss:=ss div d;
 write(ss div 100,'.');
 if ((ss mod 100)<10) then write('0');
 writeln(ss mod 100);
end.




