var
 i,n,l:longint;
begin
 read(n);
 l:=trunc(sqrt(n))+2;
 for i:=3 to l do
  if ((n mod i)=0)
   then
    begin
     n:=i;
     break;
    end;
 writeln(n-1);
end.