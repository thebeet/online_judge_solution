var
 n,m,i,j,t:longint;
 flag:boolean;
 nn:array [0..1000] of longint;
 bb:array [0..10000] of longint;
begin
 flag:=true;
 read(n,m);
 if (m>n) then begin writeln('NO');exit;end;
 for i:=1 to m do
  begin
   read(nn[i]);
   if (nn[i]>n) then flag:=false;
  end;
 for i:=1 to m do
  for j:=(i+1) to m do
   if (nn[i]>nn[j]) then begin t:=nn[i];nn[i]:=nn[j];nn[j]:=t;end;
 fillchar(bb,sizeof(bb),0);
 bb[0]:=1;
 for j:=1 to m do
  begin
   i:=nn[j];
   if (bb[i]<1) then inc(bb[i]) else
   if (bb[i+1]<1) then inc(bb[i+1]) else
   flag:=false;
  end;
 if bb[n+1]>0 then flag:=false;
 if flag then writeln('YES')
         else writeln('NO');
end.