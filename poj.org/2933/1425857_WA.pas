var
  i,n,m,l,j,k:longint;
  p:array [0..100] of longint;
  dp:array [0..100] of longint;
  d:array [0..100,0..100] of longint;

function mn(n1,n2:longint):longint;
  begin
    if n1>n2 then exit(n2) else exit(n1);
  end;

begin
  readln(n);
  fillchar(p,sizeof(p),0);
  fillchar(dp,sizeof(dp),127);
  fillchar(d,sizeof(d),127);
  for i:=1 to n do
    readln(p[i]);
  for i:=1 to n do
    begin
      d[i,i]:=0;
      for j:=(i+1) to n do
        begin
          if ((p[j]>p[i]) and ((d[i,j-1]=1) or (d[i,j-1]=0))) then d[i,j]:=1;
          if ((p[j]<p[i]) and ((d[i,j-1]=-1) or (d[i,j-1]=0))) then d[i,j]:=0;
          if (p[j]=p[i]) then d[i,j]:=d[i,j-1];
          if (d[i,j]>10) then break;
        end;
    end;
  dp[0]:=0;
  for j:=1 to n do
    for k:=1 to j do
      if (d[k,j]<100)
        then
          dp[j]:=mn(dp[j],dp[k-1]+1);
  writeln(dp[n]);
end.




