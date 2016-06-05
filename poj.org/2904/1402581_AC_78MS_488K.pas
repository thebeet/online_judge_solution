var
  ti,tn,i,k,m,f,t,h,l,mm:longint;
  dp:array [0..10,0..101,0..101] of longint;

function mx(n1,n2:longint):longint;
  begin
    if (n1>n2) then exit(n1) else exit(n2);
  end;

begin
  readln(tn);
  fillchar(dp,sizeof(dp),0);
  for f:=1 to 100 do
    for t:=f to 100 do
      dp[1,f,t]:=dp[1,f,t-1]+t;
  for k:=2 to 10 do
    for f:=100 downto 1 do
      for t:=100 downto f do
        begin
          mm:=f+dp[k,f+1,t];
          for h:=(f+1) to (t-1) do
            begin
              l:=h+mx(dp[k,h+1,t],dp[k-1,f,h-1]);
              if (mm>l) then mm:=l;
            end;
          l:=t+dp[k-1,f,t-1];
          if (mm>l) then mm:=l;
          dp[k,f,t]:=mm;
        end;
  for ti:=1 to tn do
    begin
      readln(k,m);
      writeln(dp[k,1,m]);
    end;
end.
