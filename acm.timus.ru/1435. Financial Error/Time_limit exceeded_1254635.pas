var
  i,n,m,l:longint;
  s,ss,ts,nnn,p1,p2:int64;
  nn:array [0..1500000] of int64;
  n10:array [0..18] of int64;

begin
  readln(n);
  n10[0]:=1;
  for i:=1 to 16 do
    n10[i]:=n10[i-1]*10;
  for i:=1 to n do
    begin
      readln(nn[i]);
      s:=s+nn[i];
    end;
  readln(ss);
  if (ss=s)
    then
      begin
        writeln('Input has no error.');
        exit;
      end;
  for i:=1 to n do
    if (nn[i]>9) then
      begin
        m:=0;
        nnn:=nn[i];
        while (nnn>9) do
          begin
            p1:=nnn mod 10;
            nnn:=nnn div 10;
            p2:=nnn mod 10;
            ts:=s;
            ts:=ts-p1*n10[m]-p2*n10[m+1]+p1*n10[m+1]+p2*n10[m];
            if ((nnn div 10)=0) and (p1=0) then break;
            if (ts=ss)
              then
                begin
                  nn[i]:=nn[i]-p1*n10[m]-p2*n10[m+1]+p1*n10[m+1]+p2*n10[m];
                  writeln('Error