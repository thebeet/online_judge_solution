var
 i,n,m,j,h,s,t,mx,k:longint;
 map,dp1,dp2:array [0..100,0..100] of longint;
begin
 read(n);
 for i:=1 to n do
  for j:=1 to n do
   read(map[i,j]);
 fillchar(dp1,sizeof(dp1),0);
 mx:=-1000;
 for i:=1 to n do
  begin
   for j:=1 to n do
    begin
     s:=0;
     for h:=j to n do
      begin
       s:=s+map[i,h];
       dp2[j,h]:=dp1[j,h]+s;
       if mx<dp2[j,h] then mx:=dp2[j,h];
       if dp2[j,h]<0 then dp2[j,h]:=0;
      end;
    end;
   dp1:=dp2;
  end;
 writeln(mx);
end.
