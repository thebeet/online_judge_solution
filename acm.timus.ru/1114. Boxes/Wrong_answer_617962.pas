{$N+}
var
 i:longint;
 n,a,b,s1,s2:extended;
function cc(a,b:extended):extended;
 var
  i:longint;
  s:extended;
 begin
  b:=b+a;
  s:=1;
  a:=a-1;
  b:=b-1;
  for i:=1 to trunc(a) do
   begin
    s:=s*b;
    b:=b-1;
    s:=s/i;
   end;
  cc:=s;
 end;
begin
 read(n,a,b);
 s1:=cc(n+1,a);
 s2:=cc(n+1,b);
 writeln(s1*s2:0:0);
end.
