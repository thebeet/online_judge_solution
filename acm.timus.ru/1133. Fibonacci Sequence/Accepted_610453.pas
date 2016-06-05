var
 i,m,px,py,d,t1:longint;
 dx,x,y,n,t:extended;
 f:array [-1..2010] of extended;
begin
 f[-1]:=0;
 f[0]:=1;
 for i:=1 to 2010 do
  f[i]:=f[i-1]+f[i-2];
 read(px,x,py,y,n);
 if px>py then begin t1:=px;px:=py;py:=t1;t:=x;x:=y;y:=t;end;{SWAP}
 d:=py-px;
 dx:=trunc((y-f[d-2]*x)/f[d-1]);
 if (n>px)
  then
   begin
    inc(px);
    while (px<>n) do
     begin
      t:=dx+x;
      x:=dx;
      dx:=t;
      inc(px);
     end;
    writeln(dx:0:0);
   end
  else
   if (n=px) then writeln(x:0:0) else
   begin
    while (px<>n) do
     begin
      t:=dx-x;
      x:=dx;
      dx:=t;
      dec(px);
     end;
    writeln(dx:0:0);
   end;
end.




end.
