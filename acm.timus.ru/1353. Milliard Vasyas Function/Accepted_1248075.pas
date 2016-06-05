var
  i,n,j,h:longint;
  dp:array [-10..100,0..10] of longint;

begin
  readln(n);
  if (n=1) then begin writeln('10');exit;end;
  fillchar(dp,sizeof(dp),0);
  dp[0,0]:=1;
  for i:=1 to 9 do
    for j:=0 to n do
      for h:=0 to 9 do
        dp[j,i]:=dp[j,i]+dp[j-h,i-1];
  writeln(dp[n,9]);
end.
