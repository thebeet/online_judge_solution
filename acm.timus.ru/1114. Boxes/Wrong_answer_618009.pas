{$N+}
var
 i,n,a,b:longint;
 s1,s2:extended;
function cc(a,b:longint):extended;
 var
  i:longint;
  s:extended;
 begin
  b:=b+a;
  s:=1;
  for i:=1 to a do
   begin
    s:=s*b;
    dec(b);
    s:=s/i;
   end;
  cc:=s;
 end;
begin
 read(n,a,b);
 if ((a=0) and (b=0)) then n:=n div a;
 s1:=cc(n,a);
 s2:=cc(n,b);
 writeln(s1*s2:0:0);
end.
