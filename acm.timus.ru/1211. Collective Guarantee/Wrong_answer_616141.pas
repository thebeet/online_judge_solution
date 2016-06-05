var
 i,j,n,m,l:longint;
 p,gone:array [0..1003] of longint;
 flag:boolean;
function ss(po,c:longint):boolean;
 begin
  if po=0 then begin ss:=true;exit;end;
  gone[po]:=-c;
  if (gone[p[po]]=0)then ss:=ss(p[po],c)
                  else if (gone[p[po]]=-c) then ss:=false
                                           else ss:=true;
 end;
begin
 read(n);
 for i:=1 to n do
  begin
   read(m);
   for j:=1 to m do
    read(p[j]);
   fillchar(gone,sizeof(gone),0);
   flag:=true;
   for j:=1 to m do
    if (gone[j]=0)
     then
      if ss(j,j)=false then begin flag:=false;break;end;
   if flag then writeln('YES') else writeln('NO');
  end;
end.
