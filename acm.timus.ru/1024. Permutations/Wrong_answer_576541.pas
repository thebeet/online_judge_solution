var
 i,n,m,s:longint;
 p:array [0..1000] of longint;
 ans:array [0..1000] of longint;
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
function se(id,m:longint):longint;
 var
  i:longint;
 begin
  if p[id]=m then se:=1
             else se:=se(p[id],m)+1;
 end;
begin
 read(n);
 for i:=1 to n do
  read(p[i]);
 for i:=1 to n do
  ans[i]:=se(i,i);
 s:=1;
 for i:=1 to n do
  if (ans[i]<>0) then s:=(s*ans[i]) div gcd(s,ans[i]);
 writeln(s);
end.
