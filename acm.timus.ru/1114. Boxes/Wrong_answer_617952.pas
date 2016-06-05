var
 i,n,m,a,b,s1,s2:longint;
function cc(a,b:longint):longint;
 var
  i,n,m,s:longint;
 begin
  b:=b+a;
  s:=1;
  dec(a);
  dec(b);
  for i:=1 to a do
   begin
    s:=s*b;
    dec(b);
    s:=s div i;
   end;
  cc:=s;
 end;
begin
 read(n,a,b);
 s1:=cc(n+1,a);
 s2:=cc(n+1,b);
 writeln(s1*s2);
end.
