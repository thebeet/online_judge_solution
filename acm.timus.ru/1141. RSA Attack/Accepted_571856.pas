var
 i,n,t,j,e,m,c,p,q,sn,d,ln,nn:longint;
 bin2:array [0..100] of longint;
function niyuan(m,u:longint):longint;
 var
  b1,b2,b3,r1,r2,r3,q:longint;
 begin
  r2:=m;r3:=u;
  b2:=0;b3:=1;
  while (r3>1) do
   begin
    r1:=r2;r2:=r3;
    b1:=b2;b2:=b3;
    q:=r1 div r2;
    r3:=r1 mod r2;
    b3:=(((b1-q*b2) mod m)+m) mod m;
   end;
  niyuan:=b3;
 end;
function mi_mod(nx,k:longint):longint;
  var
   i,ans:longint;
  begin
   ans:=1;
   for i:=ln downto 1 do
    if (bin2[i]=1)
     then
      ans:=(((ans*ans) mod k)*nx) mod k
     else
      ans:=(ans*ans) mod k;
   mi_mod:=ans;
  end;
begin
 read(nn);
 for i:=1 to nn do
  begin
   read(e,n,c);
   for j:=2 to trunc(sqrt(n)) do
    if ((n mod j)=0) then begin q:=j;p:=n div j;break;end;
   sn:=(q-1)*(p-1);
   d:=niyuan(sn,e);
   ln:=0;
   while (d>0) do
    begin
     inc(ln);
     bin2[ln]:=d mod 2;
     d:=d div 2;
    end;
   m:=mi_mod(c,n);
   writeln(m);
  end;
end.