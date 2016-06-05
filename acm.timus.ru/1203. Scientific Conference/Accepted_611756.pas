var
 i,n,m,s,e:longint;
 dp:array [0..30000] of integer;
begin
 read(n);
 for i:=1 to n do
  begin
   read(s,e);
   if ((dp[e]<s)) then dp[e]:=s;
  end;
 for i:=1 to 30000 do
  if (dp[i]>0)
   then
    if (dp[dp[i]-1]+1>dp[i-1]) then dp[i]:=dp[dp[i]-1]+1 else dp[i]:=dp[i-1]
   else
    dp[i]:=dp[i-1];
 writeln(dp[30000]);
end.

