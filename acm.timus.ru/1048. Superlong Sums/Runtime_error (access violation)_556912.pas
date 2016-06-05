type
 hp=array [0..100000] of byte;
var
 i,n:longint;
 tmp,tt:byte;
 num1,num2:hp;
begin
 read(n);
 for i:=1 to n do
  read(num1[i],num2[i]);
 tmp:=0;
 for i:=n downto 1 do
  begin
   tt:=(num1[i]+num2[i]+tmp) mod 10;
   tmp:=(num1[i]+num2[i]) div 10;
   num1[i]:=tt;
  end;
 if (tmp<>0) then write(tmp);
 for i:=1 to n do write(num1[i]);
 writeln;
end.
