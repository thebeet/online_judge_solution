var
  i,na,nb,m:longint;
  a,b,c:double;

begin
  read(a,b);
  a:=a/100;
  b:=b/100;
  i:=1;
  while true do
    begin
      na:=trunc(i*a);
      if ((na+1)<i*b-0.000000001) then break;
      inc(i);
    end;
  writeln(i);
end.