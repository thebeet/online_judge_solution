var
 r,a,t:double;
 i,p,n:longint;
begin
 read(n);
 p:=n;
 for i:=p downto 1 do
  begin
   r:=(n/i-(i/2)+0.5);
   t:=trunc(r);
   if ((r=t) and (t>0)) then begin writeln(t:0:0,' ',i);exit;end;
  end;
end.
