var
 p:array [0..200000] of longint;
 i,n,m,t,k:longint;
begin
 fillchar(p,sizeof(p),0);
 for i:=2 to 200000 do
  if (p[i]=0)
   then
    begin
     t:=i+i;
     while (t<=200000) do
      begin
       p[t]:=1;
       t:=t+i;
      end;
    end;
 k:=0;
 for i:=2 to 200000 do
  if p[i]=0
   then
    begin
     inc(k);
     p[k]:=i;
    end;
 read(n);
 for i:=1 to n do
  begin
   read(k);
   writeln(p[k]);
  end;
end.