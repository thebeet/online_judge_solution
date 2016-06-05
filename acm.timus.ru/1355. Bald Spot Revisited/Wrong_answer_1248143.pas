var
ti,tn,i,n,m,a,b:longint;

begin
readln(tn);
for ti:=1 to tn do
begin
readln(a,b);
if ((b mod a)<>0) then begin writeln('0');continue;end;
b:=b div a;
m:=1;
for i:=2 to trunc(sqrt(b)) do
if ((b mod i)=0)
then
begin
b:=b div i;
{m:=m+1;
i:=i-1;}
end;
if (b>1) then inc(m);
writeln(m);
end;
end.
