var
  i,n,m,l,a1,a2:longint;
  f:array [0..501] of longint;

begin
  readln(n);
  fillchar(f,sizeof(f),0);
  m:=0;
  for i:=1 to n do
    begin
      read(l);
      inc(f[l]);
      if l>m then m:=l;
    end;
  a2:=m;
  for i:=1 to 500 do
    if (f[i]>0)
      then
        begin
          l:=i;
          break;
        end;
  while (l<m) do
    begin
      dec(f[l]);
      inc(f[l-1]);
      dec(f[m]);
      inc(f[m-1]);
      while (f[m]=0) do
        dec(m);
      dec(l);
      if (l=0)
        then
          for i:=1 to 500 do
            if (f[i]>0)
              then
                begin
                  l:=i;
                  break;
               end;
    end;
  if (f[l]>1) then a1:=1 else a1:=l;
  writeln(a1,' ',a2);
end.