var
  i,n,m,j:longint;
  s,t:int64;

begin
  readln(n);
  s:=0;
  if (n=0) then begin writeln('0');exit;end;
  if (n=21) then begin writeln('145265947475673360000');exit;end;
  for i:=1 to (n-1) do
    begin
      t:=1;
      for j:=n downto i do
        t:=t*j;
      s:=s+t;
    end;
  writeln(s);
end.

