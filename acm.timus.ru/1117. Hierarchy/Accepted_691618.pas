var
 i,n1,n2,t:longint;
 s1,s2:int64;

function solve(nn:longint):int64;
 var
  i:longint;
  s,p:int64;
 begin
  i:=0;
  p:=1;
  s:=0;
  while (nn>=(p shl 1)) do
   begin
    s:=s+s+i;
    p:=p shl 1;
    inc(i);
   end;
  if ((nn-p)=0) then exit(s);
  s:=s+i-1;
  if ((nn-p)=1) then exit(s);
  solve:=solve(nn-p)+s;
 end;

begin
 readln(n1,n2);
 if (n1>=n2) then begin t:=n1;n1:=n2;n2:=t;end;
 s1:=solve(n1);
 s2:=solve(n2);
 writeln(s2-s1);
end.