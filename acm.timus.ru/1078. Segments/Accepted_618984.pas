type
 line=record
       s,e,id:integer;
      end;
 theans=record
         l,p:integer;
        end;
var
 i,j,n,m,p:longint;
 ls:array [1..499] of line;
 ans:array [1..499] of theans;
 tmp:line;
function cc(ls2,ls1:line):boolean;
 begin
  if ((ls1.s<ls2.s) and (ls1.e>ls2.e))
   then
    cc:=true
   else
    cc:=false;
 end;
procedure out(p:integer);
 begin
  if ans[p].p<>0 then out(ans[p].p);
  write(ls[p].id,' ');
 end;
begin
 read(n);
 for i:=1 to n do
  begin
   read(ls[i].s,ls[i].e);
   ls[i].id:=i;
  end;
 for i:=1 to n do
  for j:=(i+1) to n do
   if ((ls[i].e-ls[i].s)>(ls[j].e-ls[j].s))
    then
     begin
      tmp:=ls[i];
      ls[i]:=ls[j];
      ls[j]:=tmp;
     end;
 m:=-1;
 for i:=1 to n do
  for j:=(i+1) to n do
   if ((ans[i].l+1>(ans[j].l)) and (cc(ls[i],ls[j])))
    then
     begin
      ans[j].l:=ans[i].l+1;
      ans[j].p:=i;
      if ans[j].l>m then begin m:=ans[j].l;p:=j;end;
     end;
 if (m>0) then
 begin
 writeln(m+1);
 out(p);
 end
 else
 begin
  writeln('1');
  writeln('1');
 end;
end.
