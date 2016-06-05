var
  i,n,m,sum:longint;
  ch:char;
  nm:array [0..2001] of longint;

procedure out;
  var
    i:longint;
  begin
    for i:=1 to n do
      write(nm[i]);
    writeln;
  end;

begin
  i:=0;
  sum:=0;
  read(ch);
  while (ord(ch)>47) do
    begin
      inc(i);
      nm[i]:=ord(ch)-48;
      read(ch);
      sum:=sum+nm[i];
    end;
  n:=i;
  if ((nm[n]>0) and (nm[n-1]<9))
    then
      begin
        dec(nm[n]);
        inc(nm[n-1]);
        out;
        exit;
      end;
  i:=n-2;
  sum:=nm[n]+nm[n-1];
  while (nm[i]=9) do
    begin
      sum:=sum+nm[i];
      dec(i);
    end;
  inc(nm[i]);
  if i=0 then begin writeln('-1');exit;end;
  dec(sum);
  for m:=(i+1) to n do
    nm[m]:=0;
  i:=n;
  while (sum<>0) do
    begin
      if (sum>9) then
        begin
          nm[i]:=9;
          sum:=sum-9;
        end
        else
          begin
            nm[i]:=sum;
            sum:=0;
          end;
      dec(i);
    end;
  out;
end.
