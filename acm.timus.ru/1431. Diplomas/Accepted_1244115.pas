var
  i,j,n,m,l,t:longint;
  d:array [0..30] of longint;

begin
  readln(n);
  fillchar(d,sizeof(d),0);
  for i:=1 to n do
    begin
      read(t);
      inc(d[t]);
    end;
  m:=n;
  for i:=1 to 29 do
    if ((d[i]<>0) and (d[i+1]<>0))
      then
        if d[i]>=d[i+1] then begin m:=m-d[i+1];d[i+1]:=0;end
                        else begin m:=m-d[i];d[i+1]:=d[i+1]-d[i];end;
  writeln(m);
end.
