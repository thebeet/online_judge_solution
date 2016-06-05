var
  ti,tn,i,n,m,l:longint;
  ss:array [0..10000] of longint;

function check(n:longint):boolean;
  var
    i,q:longint;
  begin
    q:=trunc(sqrt(n));
    for i:=2 to q do
      if ((n mod i)=0) then exit(false);
    check:=true;
  end;

begin
  fillchar(ss,sizeof(ss),0);
  m:=0;
  for i:=2 to 100 do
    if (ss[i]=0)
      then
        begin
          inc(m);
          ss[m]:=i;
          n:=i*i;
          while (n<10001) do
            begin
              ss[n]:=1;
              n:=n+i;
            end;
        end;
  readln(tn);
  for ti:=1 to tn do
    begin
      readln(n);
      if check(n) then begin writeln(n);continue;end;
      if ((n mod 2)=1)
        then
          begin
            if check(n-2) then begin writeln(2,' ',n-2);continue;end;
            write('3 ');
            n:=n-3;
          end;
      for i:=1 to m do
        if check(n-ss[i])
          then
            begin
              writeln(ss[i],' ',n-ss[i]);
              break;
            end;
    end;
end.
