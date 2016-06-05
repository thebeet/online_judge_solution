var
 i,n,m,s:longint;
 num:array [0..30000] of byte;
 dp:array [0..30000] of longint;
begin
 read(s,n);
 for i:=1 to s do
  begin
   read(num[i]);
   if (num[i]>n+1) then begin writeln('NO');exit;end;
  end;
 dp[1]:=num[1];
 for i:=2 to s do
  begin
   dp[i]:=dp[i-1]-1+num[i];
   if dp[i-1]>dp[i] then dp[i]:=dp[i-1];
   if (dp[i]>n+1) then begin writeln('NO');exit;end;
  end;
 writeln('YES');
end.
