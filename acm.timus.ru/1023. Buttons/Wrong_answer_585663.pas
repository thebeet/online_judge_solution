program ex;
var
now,i,l,k:longint;
begin
readln(k);
now:=k;
for i:=3 to trunc(sqrt(k)) do
if k mod i=0 then begin now:=i; break; end;
writeln(now-1);
end.


