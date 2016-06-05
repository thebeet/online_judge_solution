const
 Max = 1000;
type
 line=record
       s,e,l,id:integer;
      end;
 theans=array [0..500] of integer;
var
 i,j,n,m,p:longint;
 ls:array [1..500] of line;
 ans:array [1..500] of theans;
 tmp:line;
function cc(ls2,ls1:line):boolean;
 begin
  if ((ls1.s<ls2.s) and (ls1.e>ls2.e))
   then
    cc:=true
   else
    cc:=false;
 end;
begin
 read(n);
 for i:=1 to n do
  begin
   read(ls[i].s,ls[i].e);
   ls[i].id:=i;
   ls[i].l:=ls[i].e-ls[i].s;
  end;
 for i:=1 to n do
  for j:=(i+1) to n do
   if (ls[i].l>ls[j].l)
    then
     begin
      tmp:=ls[i];
      ls[i]:=ls[j];
      ls[j]:=tmp;
     end;
 m:=-1;
 for i:=1 to n do
  for j:=(i+1) to n do
   if ((ans[i,0]+1>(ans[j,0])) and (cc(ls[i],ls[j])))
    then
     begin
      ans[j]:=ans[i];
      inc(ans[j,0]);
      ans[j,ans[j,0]]:=i;
      if ans[j,0]>m then begin m:=ans[j,0];p:=j;end;
     end;
 if (m>0) then
 begin
 writeln(m+1)