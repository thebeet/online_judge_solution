var
 i,d,e,f,dp,ep,h,s,t:longint;
begin
 read(D,E,F,Dp,Ep,H);
 dec(dp);
 dec(ep);
 for i:=1 to d do
  dp:=dp div 2;
 for i:=1 to e do
  ep:=ep div 2;
 s:=0;
 if (d>e) then for i:=1 to (d-e) do begin ep:=ep div 2;inc(s);end;
 if (e>d) then for i:=1 to (e-d) do begin dp:=dp div 2;inc(s);end;
 for i:=1 to f do
  begin
   if ep=dp then break;
   ep:=ep div 2;
   dp:=dp div 2;
   s:=s+2;
  end;
 if (s>h) then writeln('NO') else writeln('YES');
end.
