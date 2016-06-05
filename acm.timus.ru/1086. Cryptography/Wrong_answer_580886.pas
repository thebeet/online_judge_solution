const
 max=163860;
var
 p:array [1..max] of byte;
 s:array [1..15001] of longint;
 i,n,m,t,k:longint;
begin
 fillchar(p,sizeof(p),0);
 for i:=2 to max do
  if (p[i]=0)
   then
    begin
     t:=i+i;
     while (t<=max) do
      begin
       p[t]:=1;
       t:=t+i;
      end;
    end;
 for i:=2 to max do
  if p[i]=0
   then
    begin
     inc(k);
     s[k]:=i;
    end;
 read(n);
 for i:=1 to n do
  begin
   read(k);
   writeln(p[k]);
  end;
end.