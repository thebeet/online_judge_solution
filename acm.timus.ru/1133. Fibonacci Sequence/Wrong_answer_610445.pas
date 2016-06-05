var
 i,m,px,py,d:longint;
 dx,x,y,n,t:int64;
 f:array [-1..3010] of int64;
begin
 f[-1]:=0;
 f[0]:=1;
 f[1]:=1;
 for i:=2 to 3010 do
  f[i]:=f[i-1]+f[i-2];
 read(px,x,py,y,n);
 if px>py then begin t:=px;px:=py;py:=t;t:=x;x:=y;y:=t;end;{SWAP}
 d:=py-px;
 dx:=(y-f[d-2]*x) div f[d-1];
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
