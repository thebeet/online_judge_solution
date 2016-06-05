const
  mm=1000;

var
  i,n,m,j,k:longint;
  dp:array [0..11,0..mm] of longint;

function mx(n1,n2:longint):longint;
  begin
    if (n1>n2) then exit(n1) else exit(n2);
  end;

function mn(n1,n2:longint):longint;
  begin
    if (n1<n2) then exit(n1) else exit(n2);
  end;

begin
  fillchar(dp,sizeof(dp),127);
  for i:=0 to mm do
    dp[1,i]:=i;
  for i:=0 to 10 do
    dp[i,0]:=0;
  for i:=2 to 10 do
    for j:=1 to mm do
      for k:=1 to j do
        dp[i,j]:=mn(dp[i,j],mx(dp[i,j-k],dp[i-1,k-1])+1);
  read(n);
  while (n>0) do
    begin
      read(m);
      if n>10 then n:=10;
      writeln(dp[n,m]);
      read(n);
    end;
end.


