var
 i:longint;
 n,a,b,s1,s2:int64;
function cc(a,b:int64):int64;
 var
  i:longint;
  s:int64;
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
