var
  i,n,m,l,t:longint;
  go:array [0..1,0..101] of longint;

begin
  readln(l,n);
  fillchar(go,sizeof(go),0);
  go[0,0]:=0;
  go[1,0]:=l;
  for i:=1 to n do
    begin
      read(t);
      go[0,i]:=go[0,i-1]+t;
      go[1,i]:=go[1,i-1];
      while (go[1,i]>go[0,i-1]) do
        go[0,i-1]:=go[0,i-1]+t;
      go[1,i]:=go[0,i-1];
      if (go[1,i-1]<=go[0,i]) then
        begin
          writeln('YES');
          exit;
        end;
    end;
  writeln('NO');
end.




