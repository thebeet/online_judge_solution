var
i,n,m,s,t:longint;
begin
read(s,n);
m:=0;
for i:=1 to s do
begin
read(t);
if ((m+t-1)>0) then m:=m+t-1;
if (m>n) then begin writeln('NO');exit;end;
end;
writeln('YES');
end.
