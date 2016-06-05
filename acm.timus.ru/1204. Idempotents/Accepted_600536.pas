procedure fj(var n,p1,p2:longint);
 var
  i,t:longint;
 begin
  if ((n mod 2)=0) then begin p1:=2;p2:=n shr 1;exit;end;
  t:=(trunc(sqrt(n)) div 2);
  for i:=1 to t do
   if ((n mod (i*2+1))=0)
    then
     begin
      p1:=i*2+1;
      p2:=n div p1;
     end;
 end;
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
var
 i,n,m,p1,p2,u:longint;
begin
 read(n);
 for i:=1 to n do
  begin
   read(m);
   fj(m,p1,p2);
   u:=niyuan(p1,p2);
   write('0 1 ');
   if ((u*p2)>(m+1-u*p2)) then writeln(m+1-u*p2,' ',u*p2)
                          else writeln(u*p2,' ',m+1-u*p2);

  end;
end.
