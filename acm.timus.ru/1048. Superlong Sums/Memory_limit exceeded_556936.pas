var
 i,n,tmp,tt,num1,num2:longint;
 numa:array [0..1000000] of byte;
begin
 read(n);
 for i:=1 to n do
  begin
   read(num1,num2);
   numa[i]:=(num1+num2) mod 10;
   numa[i-1]:=numa[i-1]+(num1+num2) div 10;
  end;
 for i:=1 to n do
  write(numa[i]);
 writeln;
end.
