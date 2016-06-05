var
 n,m,i,j,t:longint;
 flag:boolean;
 nn:array [0..1000] of longint;
 bb:array [0..1000] of boolean;
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
 fillchar(bb,sizeof(bb),false);
 bb[0]:=true;
 for j:=1 to m do
  begin
   i:=nn[j];
   if (bb[i-1]=false) then begin bb[i-1]:=true;continue;end;
   if (bb[i]=false) then begin bb[i]:=true;continue;end;
   flag:=false;
   continue;
  end;
 if flag then writeln('YES')
         else writeln('NO');
end.