var
 i,n,a,b,m,j,mx,s,p,nn:longint;
begin
 read(a,b);
 mx:=100000;
 nn:=a;
 for i:=a to b do
  begin
   s:=i+1;
   p:=trunc(sqrt(i));
   if (p*p=i) then s:=s-p;
   for j:=2 to p do
    if ((i mod j)=0) then begin s:=s+j;s:=s+i div j;if s>mx then break;end;
   if (mx>s) then begin mx:=s;nn:=i;end;
  end;
 writeln(nn);
end.