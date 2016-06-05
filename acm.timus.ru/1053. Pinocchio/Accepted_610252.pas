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
var
 i,n,ans,t:longint;
begin
  read(n);
  read(ans);
  for i:=2 to n do
   begin
    read(t);
    ans:=gcd(ans,t);
   end;
  writeln(ans);
end.

