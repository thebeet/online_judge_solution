var
  i,n,id2,_id2,id2p,_id2p,j,k,h:longint;
  s:int64;
  dp:array [0..10,0..200,0..200] of int64;

begin
  fillchar(dp,sizeof(dp),0);
  for i:=0 to 9 do
    dp[1,i,0]:=1;
  for i:=2 to 10 do
    begin
      _id2p:=((i-1) div 2)*9;
      id2p:=(i div 2)*9;
      if ((i mod 2)=0)
        then
          for j:=0 to id2p do
            for k:=0 to _id2p do
              for h:=0 to 9 do
                dp[i,j,k+h]:=dp[i,j,k+h]+dp[i-1,j,k];
      if ((i mod 2)=1)
        then
          for j:=0 to id2p do
            for k:=0 to _id2p do
              for h:=0 to 9 do
                dp[i,j+h,k]:=dp[i,j+h,k]+dp[i-1,j,k];
    end;
  readln(n);
  s:=0;
  for i:=0 to 200 do
    for j:=0 to 200 do
      s:=s+dp[n div 2,i,j]*dp[n div 2,i,j];
  writeln(s);
end.