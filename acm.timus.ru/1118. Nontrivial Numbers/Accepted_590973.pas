var
 i,n,a,b,m,j,p,nn:longint;
 s,mx:int64;
begin
 read(a,b);
 mx:=10000000;
 nn:=a;
 if a=1 then begin writeln('1');exit;end;
 for i:=b downto a do
  if (mx=1) then break else
  begin
   s:=1;
   p:=trunc(sqrt(i));
   if (p*p=i) then s:=s-p;
   for j:=2 to p do
    if ((i mod j)=0) then begin s:=s+j;s:=s+(i div j);if (s>mx) then break;end;
   if (mx*i>s*nn) then begin mx:=s;nn:=i;end;
  end;
 writeln(nn);
end.
