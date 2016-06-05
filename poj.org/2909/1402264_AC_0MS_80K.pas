var
  i,n,m,k,l,s:longint;
  ss:array [0..40000] of boolean;
begin
  fillchar(ss,sizeof(ss),true);
  for i:=2 to 200 do
    if ss[i]
      then
        begin
          n:=i*i;
          while (n<40000) do
            begin
              ss[n]:=false;
              n:=n+i;
            end;
        end;
  readln(n);
  while (n>0) do
    begin
      s:=0;
      for i:=2 to (n shr 1) do
        if (ss[i] and ss[n-i]) then inc(s);
      writeln(s);
      readln(n);
    end;
end.
