var
 i,n,m,x,y,px,py,d,t,dx:longint;
 f:array [-1001..1001] of longint;
begin
 read(px,x,py,y,n);
 if px>py then begin t:=px;px:=py;py:=t;t:=x;x:=y;y:=t;end;{SWAP}
 d:=py-px;
 dx:=(y-(d-1)*x) div d;
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
    writeln(dx);
   end
  else
   if (n=px) then writeln(x) else
   begin
    while (px<>n) do
     begin
      t:=dx-x;
      x:=dx;
      dx:=t;
      dec(px);
     end;
    writeln(dx);
   end;
end.




end.
