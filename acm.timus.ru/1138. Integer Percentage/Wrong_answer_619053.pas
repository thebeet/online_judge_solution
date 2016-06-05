var
 I,s,n,j:longint;
 dp:array [0..10000] of longint;
begin
 read(n,s);
 fillchar(dp,sizeof(dp),0);
 dp[s]:=1;
 for i:=s to n do
  begin
   for j:=1 to 100 do
    if (((i*100) div (100+j))*(100+j)=(i*100))
     then
      if ((dp[((i*100) div (100+j))]+1)>dp[i])
       then
        dp[i]:=dp[((i*100) div (100+j))]+1;
  end;
 writeln(dp[n]);
end.
