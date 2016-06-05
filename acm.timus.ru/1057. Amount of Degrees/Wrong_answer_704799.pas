type
 num=array [0..100] of longint;

var
 nx,ny:num;
 x,y,b,n,k,dx,dy:longint;

function c(n,m:longint):longint;
 var
  i,s,k:longint;
 begin
  s:=1;k:=0;
  if (n>(m div 2)) then n:=m-n;
  for i:=(m-n+1) to m do
   begin
    inc(k);
    s:=(s*i) div k;
   end;
  exit(s);
 end;

procedure turndown(var n1:num);
 var
  i,j:longint;
 begin
  for i:=n1[0] downto 1 do
   if (n1[i]>1) then break;
  if (n1[i]>1) then n1[i]:=1;
  for j:=1 to (i-1) do
   n1[j]:=1;
 end;

procedure breakup(var n1:num;n,k:longint);
 begin
  fillchar(n1,sizeof(n1),0);
  while (n>0) do
   begin
    inc(n1[0]);
    n1[n1[0]]:=n mod k;
    n:=n div k;
   end;
  turndown(n1);
 end;

function cate(var n1:num;b:longint):longint;
 var
  i,l,p,s:longint;
 begin
  s:=0;
  for i:=n1[0] downto 1 do
   begin
    if ((b>i) or (b=0)) then break;
    if (n1[i]<>1) then continue;
    if ((i-1)>=b) then s:=s+c(b,(i-1));
    dec(b);
   end;
  if ((b=0) and (i=1)) then inc(s);
  exit(s);
 end;

begin
 read(x,y,k,b);
 breakup(nx,x,k);
 breakup(ny,y,k);
 dx:=cate(nx,b);
 dy:=cate(ny,b);
 writeln(dy-dx);
end.

