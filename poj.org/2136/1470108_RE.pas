var
  i,m,j,p:longint;
  st:string;
  chs:array [60..100] of longint;

begin
  fillchar(chs,sizeof(chs),0);
  for i:=1 to 4 do
    begin
      readln(st);
      for j:=1 to length(st) do
        inc(chs[ord(st[j])]);
    end;
  m:=0;
  for i:=65 to 90 do
    if (m<chs[i]) then m:=chs[i];
  while (m>0) do
    begin
      p:=131;
      for i:=65 to 90 do
        if (m<=chs[i])
          then
            begin
              for j:=p to (i*2) do
                write(' ');
              p:=i*2+2;
              write('*');
            end;
      writeln;
      dec(m);
    end;
  for i:=65 to 89 do
    write(chr(i),' ');
  writeln('Z');
end.


