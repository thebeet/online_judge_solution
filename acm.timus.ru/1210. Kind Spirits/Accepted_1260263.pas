var
  i,j,n,m,k,l,d,p,p1:longint;
  dp:array [0..1,0..100] of longint;

function mn(n1,n2:longint):longint;
  begin
    if (n1<n2) then exit(n1) else exit(n2);
  end;

begin
  readln(n);
  fillchar(dp,sizeof(dp),127);
  dp[0,1]:=0;
  p:=0;
  p1:=1;
  for i:=1 to n do
    begin
      fillchar(dp[p1],sizeof(dp[p1]),127);
      readln(m);
      for j:=1 to m do
        begin
          read(l);
          while (l>0) do
            begin
              read(d);
              dp[p1,j]:=mn(dp[p1,j],dp[p,l]+d);
              read(l);
            end;
          readln;
        end;
      p:=p xor 1;
      p1:=p1 xor 1;
      if (i<>n) then readln;
    end;
  m:=1000000000;
  for i:=1 to 100 do
    m:=mn(dp[p,i],m);
  writeln(m);
end.

