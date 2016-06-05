var
 I,s,n,j,t:longint;
 dp:array [0..10000] of longint;
begin
 read(n,s);
 fillchar(dp,sizeof(dp),0);
 dp[s]:=1;
 for i:=s to n do
  begin
   for j:=1 to 100 do
    begin
     t:=(i*100) div (100+j);
     if (t*(100+j)=(i*100))
      then
       if (t>=s) and ((dp[t]+1)>dp[i])
        then
         dp[i]:=dp[t]+1;
    end;
  end;
 writeln(dp[n]);
end.
