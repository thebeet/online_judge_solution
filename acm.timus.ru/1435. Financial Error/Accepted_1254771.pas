var
  i,n,m,l:longint;
  s,ss,ts,nnn,p1,p2,d,mm:int64;
  flag:boolean;
  ch:char;
  nn:array [0..1500000] of string[16];
  n10:array [0..18] of int64;

begin
  readln(n);
  n10[0]:=1;
  for i:=1 to 18 do
    n10[i]:=n10[i-1]*10;
  for i:=1 to n do
    begin
      readln(nn[i]);
      val(nn[i],d);
      s:=s+d;
    end;
  readln(ss);
  if (ss=s)
    then
      begin
        writeln('Input has no error.');
        exit;
      end;
  d:=ss-s;
  mm:=0;
  while ((d mod 10)=0) do
    begin
      d:=d div 10;
      inc(mm);
    end;
  if (((d mod 9)<>0) or (d>81)) then begin writeln('Unrecoverable error.');exit;end;
  d:=d div 9;
  for i:=1 to n do
    if (length(nn[i])>(mm+1)) then
      begin
      p1:=length(nn[i])-(mm+1);
      p2:=p1+1;
      if (ord(nn[i,p2])-ord(nn[i,p1])=d) and ((length(nn[i])>(mm+2)) or (nn[i,p2]<>'0'))
      then
        begin
          ch:=nn[i,p1];
          nn[i,p1]:=nn[i,p2];
          nn[i,p2]:=ch;
          writeln('Error in record #',i,'. Correct number is: ',nn[i],'.');
          exit;
        end;
    end;
  writeln('Unrecoverable error.');
end.