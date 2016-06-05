type
  map=array [-10..40,-10..40] of longint;
  dd=array [-10..40,-10..40] of int64;

var
  tm:map;
  dp:dd;
  ch:char;
  i,j,n,h:longint;

begin
  readln(n);
  while (n<>-1) do
    begin
      {}
      fillchar(tm,sizeof(tm),0);
      fillchar(dp,sizeof(dp),0);
      for i:=1 to n do
        begin
          for j:=1 to n do
            begin
              read(ch);
              tm[i,j]:=ord(ch)-48;
            end;
          readln;
        end;
      {}
      dp[1,1]:=1;
      for i:=1 to n do
        for j:=1 to n do
          for h:=1 to 9 do
            begin
              if tm[i-h,j]=h then dp[i,j]:=dp[i,j]+dp[i-h,j];
              if tm[i,j-h]=h then dp[i,j]:=dp[i,j]+dp[i,j-h];
            end;

      writeln(dp[n,n]);
      readln(n);
    end;
end.
