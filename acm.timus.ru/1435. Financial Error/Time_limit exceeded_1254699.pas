var
  i,n,m,l:longint;
  s,ss,ts,nnn,p1,p2:int64;
  flag:boolean;
  nn:array [0..1500000] of int64;
  n10:array [0..18] of int64;

begin
  readln(n);
  n10[0]:=1;
  for i:=1 to 18 do
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
  if ss>s then flag:=true else flag:=false;
  for i:=1 to n do
    if (nn[i]>9) then
      begin
        m:=0;
        nnn:=nn[i];
        p2:=nnn mod 10;
        while (nnn>9) do
          begin
            p1:=p2;
            nnn:=nnn div 10;
            p2:=nnn mod 10;
            {if flag
              then
                begin
                  if (p1<=p2) then begin inc(m);continue;end;
                end
              else
                if (p2>=p1) then begin inc(m);continue;end;}
            ts:=s;
            ts:=ts-p1*n10[m]-p2*n10[m+1]+p1*n10[m+1]+p2*n10[m];
            if ((p1=0) and ((nnn div 10)=0)) then break;
            if (ts=ss)
              then
                begin
                  nn[i]:=nn[i]-p1*n10[m]-p2*n10[m+1]+p1*n10[m+1]+p2*n10[m];
                  writeln('Error in record #',i,'. Correct number is: ',nn[i],'.');
                  exit;
                end;
            inc(m);
          end;
      end;
  writeln('Unrecoverable error.');
end.