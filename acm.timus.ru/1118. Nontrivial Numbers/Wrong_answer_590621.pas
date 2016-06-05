var
 i,n,a,b,m,j,mx,s,p,nn:longint;
begin
 read(a,b);
 mx:=100000;
 nn:=a;
 for i:=a to b do
  if (mx>i+1) then
  begin
   s:=0;
   for j:=1 to i do
    if ((i mod j)=0) then begin s:=s+j;if s>=mx then break;end;
   if (mx>s) then begin mx:=s;nn:=i;end;
  end;
 writeln(nn);
end.