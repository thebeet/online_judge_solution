var
 i,n,m,ln,y,x:longint;
 bin2:array [0..100] of longint;
 ff:boolean;
function mi_mod(nx,k:longint):longint;
 var
  i,ans,x:longint;
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
 ff:=true;
 readln(n,m,y);
 ln:=0;
 while (n>0) do
  begin
   inc(ln);
   bin2[ln]:=n mod 2;
   n:=n div 2;
  end;
 for x:=0 to (m-1) do
  if (mi_mod(x,m)=y)
   then
    if ff then write(x,' ') else begin ff:=false;write(x);end;
 writeln;
 end.