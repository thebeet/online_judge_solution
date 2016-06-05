var
 i,a,b,xa,xb,ya,yb,x,y,h:longint;
begin
 read(a,b);
 ya:=0;
 yb:=0;
 while ((a mod 2)=0) do
  begin
   a:=a shr 1;
   inc(ya);
  end;
 while ((b mod 2)=0) do
  begin
   b:=b shr 1;
   inc(yb);
  end;
 xa:=(a+1) shr 1;
 xb:=(b+1) shr 1;
 for i:=(ya+1) to yb do
  xa:=(xa+1) shr 1;
 for i:=(yb+1) to ya do
  xb:=(xb+1) shr 1;
 h:=0;
 while (xa<>xb) do
  begin
   inc(h);
   xa:=(xa+1) shr 1;
   xb:=(xb+1) shr 1;
  end;
 if yb>ya then h:=h+yb else h:=h+ya;
 writeln((h-yb-1)+(h-ya-1));
end.
