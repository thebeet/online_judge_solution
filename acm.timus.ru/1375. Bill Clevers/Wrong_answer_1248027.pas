var
  i:longint;
  k,p,n:int64;
  pp:array [0..1000000] of int64;

begin
  fillchar(pp,sizeof(pp),0);
  readln(k,p);
  if ((p=2) and (k=1)) then begin writeln('1 0');exit;end;
  for i:=0 to p do
    pp[i]:=-1;
  for i:=0 to ((p-1) div 2) do
    begin
      n:=i;
      n:=(n*n) mod p;
      pp[n]:=i;
    end;
  for i:=k downto 0 do
    if ((pp[i]>-1) and (pp[k-i]>-1)) then begin writeln(pp[i],' ',pp[k-i]);exit;end;
end.