var
  i:longint;
  k,p,n:int64;
  pp:array [0..1000001] of int64;

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
  for i:=k downto -p do
    if ((pp[(i+p) mod p]>-1) and (pp[(k-i+p) mod p]>-1)) then begin writeln(pp[(i+p) mod p],' ',pp[(k-i+p) mod p]);exit;end;
end.