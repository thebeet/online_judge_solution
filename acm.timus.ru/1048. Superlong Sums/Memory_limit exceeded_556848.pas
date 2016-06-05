type
 hp=array [0..1000000] of longint;
var
 i,n,tmp:longint;
 num1,num2,num3:hp;
begin
 read(n);
 for i:=1 to n do
  read(num1[i],num2[i]);
 tmp:=0;
 for i:=n downto 1 do
  begin
   num3[i]:=(num1[i]+num2[i]+tmp) mod 10;
   tmp:=(num1[i]+num2[i]) div 10;
  end;
 if (tmp<>0) then write(tmp);
 for i:=1 to n
 do write(num3[i]);
 writeln;
end.
