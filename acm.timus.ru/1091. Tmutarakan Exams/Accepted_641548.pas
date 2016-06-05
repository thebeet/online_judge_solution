var
 i,n,m,s,k:longint;
function gcd(num1,num2:longint):longint;
 var
  num3:longint;
 begin
  while (num2>0) do
   begin
    num3:=num2;
    num2:=num1 mod num2;
    num1:=num3;
   end;
  gcd:=num1;
 end;
procedure ss(m,p,lim:longint);
 var
  i,t:longint;
 begin
  if lim=0 then begin inc(n);if n=10000 then begin writeln('10000');halt;end;exit;end;
  for i:=(p+1) to (s-lim+1) do
   begin
    t:=gcd(m,i);
    if t<>1 then ss(t,i,lim-1);
   end;
 end;
begin
 readln(k,s);
 n:=0;
 ss(0,0,k);
 writeln(n);
end.
