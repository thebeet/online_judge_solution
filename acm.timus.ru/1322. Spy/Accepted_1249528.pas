var
  i,n,m,p:longint;
  chs:array [0..100000] of char;
  ls:array [63..125] of longint;
  next:array [0..100000] of longint;
  ch:char;

begin
  readln(m);
  fillchar(chs,sizeof(chs),0);
  fillchar(ls,sizeof(ls),0);
  read(chs[1]);
  n:=1;
  while (ord(chs[n])>40) do
    begin
      inc(ls[ord(chs[n])+1]);
      inc(n);
      read(chs[n]);
    end;
  dec(n);
  for i:=65 to 124 do
    ls[i]:=ls[i-1]+ls[i];
  for i:=1 to n do
    begin
      inc(ls[ord(chs[i])]);
      next[ls[ord(chs[i])]]:=i;
    end;
  for i:=1 to n do
    begin
      write(chs[next[m]]);
      m:=next[m];
    end;
  writeln;
end.
