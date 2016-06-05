var
 i,n,m,x,y,px,py,d,t,dx:longint;
 f:array [0..2010] of longint;
begin
 f[0]:=1;
 f[1]:=1;
 for i:=2 to 2010 do
  f[i]:=f[i-1]+f[i-2];
 read(px,x,py,y,n);
 if px>py then begin t:=px;px:=py;py:=t;t:=x;x:=y;y:=t;end;{SWAP}
 d:=py-px;
 dx:=(y-f[d-1]*x) div f[d];
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
