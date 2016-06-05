var
 n,i,it,tmp:longint;
 dd:array [0..9] of longint;
begin
 readln(n);
 for i:=1 to n do
  begin
   it:=i;
   while (it>0) do
    begin
     tmp:=it mod 10;
     inc(dd[tmp]);
     it:=it div 10;
    end;
  end;
 for i:=0 to 9 do
  writeln(dd[i]);
end.