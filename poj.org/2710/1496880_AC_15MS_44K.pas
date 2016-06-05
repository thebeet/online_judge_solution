var
  ti,i,j,nn,n,d,b,e:longint;
  ans:array [0..300] of longint;

begin
  readln(nn);
  for ti:=1 to nn do
    begin
      readln(n,d,b,e);
      write('Problem set ',ti,': ',n,' / ',d,', base 7 digits ',b,' through ',e,': ');
      fillchar(ans,sizeof(ans),0);
      j:=0;
      n:=n mod d;
      while (j<=e) do
        begin
          ans[j]:=(n*7) div d;
          inc(j);
          n:=(n*7) mod d;
        end;
      for i:=b to e do
        write(ans[i]);
      writeln;
    end;
end.
