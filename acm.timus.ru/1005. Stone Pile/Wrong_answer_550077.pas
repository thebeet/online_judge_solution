type
 sb=array [0..200] of longint;
var
 i,n,mn:longint;
 st:array [0..200] of longint;
 msb:sb;
procedure ss(tsb:sb);
 var
  sum,i:longint;
 begin
  if (tsb[0]=n)
   then
    begin
     sum:=0;
     for i:=1 to n do
      sum:=sum+tsb[i];
     if (abs(sum)<mn) then mn:=abs(sum);
    end
   else
    begin
     inc(tsb[0]);
     tsb[tsb[0]]:=st[tsb[0]];
     ss(tsb);
     tsb[tsb[0]]:=-st[tsb[0]];
     ss(tsb);
    end;
 end;
begin
 fillchar(msb,sizeof(msb),0);
 mn:=1000000000;
 readln(n);
 for i:=1 to n do
  readln(st[i]);
 ss(msb);
 writeln(mn);
end.
