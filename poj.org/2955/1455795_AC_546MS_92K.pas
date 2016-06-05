var
  i,j,n,m,l,s,k:longint;
  dp:array [0..110,0..110] of longint;
  st:string;

function mx(a,b:longint):longint;
  begin
    if (a>b) then exit(a) else exit(b);
  end;

begin
  readln(st);
  while (st<>'end') do
    begin
      fillchar(dp,sizeof(dp),0);
      n:=length(st);
      for j:=1 to n do
        for i:=1 to (n-j) do
          begin
            s:=i+j;
            if ((st[i]='(') and (st[s]=')')) or ((st[i]='[') and (st[s]=']'))
              then
                dp[i,s]:=mx(dp[i,s],dp[i+1,s-1]+2);
            for k:=(i+1) to s do
                dp[i,s]:=mx(dp[i,s],dp[i,k-1]+dp[k,s]);
          end;
      writeln(dp[1,n]);
      readln(st);
    end;
  end.
