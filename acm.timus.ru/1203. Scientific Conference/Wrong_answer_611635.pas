var
 i,n,m,s,e:longint;
 dp,dp2:array [0..30000] of longint;
begin
 fillchar(dp,sizeof(dp),0);
 read(n);
 for i:=1 to n do
  begin
   read(s,e);
   if ((dp[e]<s)) then dp[e]:=s;
  end;
 for i:=1 to 30000 do
  if (dp[i]>0)
   then
    dp2[i]:=dp2[dp[i]-1]+1
   else
    dp2[i]:=dp2[i-1];
 writeln(dp2[30000]);
end.

