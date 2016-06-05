var
 r,a:double;
 i,p,n,t:longint;
begin
 read(n);
 p:=(n div 2)+1;
 for i:=p downto 1 do
  begin
   if (((n*2) mod i)=0) then begin
   r:=(n/i-(i/2)+0.5);
   t:=trunc(r);
   if ((r=t) and (t>0)) then begin writeln(t,' ',i);exit;end;
   end;
  end;
end.
