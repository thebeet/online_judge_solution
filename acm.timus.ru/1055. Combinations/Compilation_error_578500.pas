var
 m,n,i,t,s,j,k,ti:longint;
 p:array [0..50000] of longint;
 ss:array [0..50000] of longint;
begin
 fillchar(ss,sizeof(ss),0);
 read(n,m);
 s:=0;
 k:=0;
 for i:=2 to n do
  begin
   if (ss[i]=0) then
    begin
     t:=i+i;
     while (t<=n) do
      begin
       ss[t]:=1;
       t:=t+i;
      end;
    end;
  end;
 for i:=2 to n do
  if (ss[i]=0) then begin inc(k);ss[k]:=i;end;
 fillchar(p,sizeof(p),0);
 if m>(n div 2) then m:=n-m;
 s:=0;
 for i:=n downto (n-m+1) do
  begin
   t:=i;
   for j:=1 to k do
    if ((t mod ss[j])=0) then begin inc(p[ss[j]]);dec(j);t:=t div ss[j+1];end;
  end;
 for i:=1 to m do
  begin
   t:=i;
   for j:=1 to k do
    if ((t mod ss[j])=0) then begin dec(p[ss[j]]);dec(j);t:=t div ss[j+1];end;
  end;
 for i:=1 to k do
  if p[ss[i]]>0 then inc(s);
 writeln(s);
end.
