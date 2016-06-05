var
 m,n,i,t,s,j,k:longint;
 p:array [0..50000] of longint;
 ss:array [0..50000] of longint;
begin
 fillchar(ss,sizeof(ss),0);
 read(m,n);
 s:=0;
 k:=0;
 for i:=2 to m do
  begin
   if (ss[i]=0) then
    begin
     t:=i+i;
     while (t<m) do
      begin
       ss[t]:=1;
       t:=t+i;
      end;
    end;
  end;
 for i:=2 to m do
  if (ss[i]=0) then begin inc(k);ss[k]:=i;end;
 fillchar(p,sizeof(p),0);
 if n>(m div 2) then n:=m-n;
 s:=0;
 for i:=m downto (m-n+1) do
   for j:=1 to k do
    if ((i mod ss[j])=0) then inc(p[ss[j]]);
 for i:=1 to n do
  for j:=1 to k do
   if ((i mod ss[j])=0) then dec(p[ss[j]]);
 for i:=1 to k do
  if p[ss[i]]>0 then inc(s);
 writeln(s);
end.