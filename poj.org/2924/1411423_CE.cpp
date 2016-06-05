var
  ti,tn:longint;
  s,a,b:int64;

begin
  readln(tn);
  for ti:=1 to tn do
    begin
      readln(a,b);
      s:=(a+b)*(b-a+1) div 2;
      writeln(s);
    end;
end.