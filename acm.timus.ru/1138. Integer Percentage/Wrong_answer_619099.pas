var
 I,s,n,j,t,m,d:longint;
 dp:array [0..10000] of longint;
begin
 read(n,s);
 d:=0;
 if s>n then n:=n div d;
 fillchar(dp,sizeof(dp),0);
 dp[s]:=1;
 m:=-1;
 for i:=s to n do
  begin
   for j:=1 to 100 do
    begin
     t:=(i*100) div (100+j);
     if ((i*100) mod (100+j)<>0) then continue;
     if (t*(100+j)=(i*100))
      then
       if (t>=s) and ((dp[t]+1)>dp[i])
        then
         dp[i]:=dp[t]+1;
    end;
   if dp[i]>m then m:=dp[i];
  end;
 if m>0 then writeln(m);
end.
