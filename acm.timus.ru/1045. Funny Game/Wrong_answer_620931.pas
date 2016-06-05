var
 i,n,m,f,t,ans:longint;
 map:array [0..1000,0..20] of longint;
function dfs(p,pe:longint):longint;
 var
  i,t,m:longint;
 begin
  for i:=1 to map[p,0] do
   if (map[p,i]<>pe) and (dfs(map[p,i],p)=0) then begin dfs:=1;exit;end;
  dfs:=0;
 end;
begin
 fillchar(map,sizeof(map),0);
 read(n,m);
 for i:=2 to n do
  begin
   read(f,t);
   inc(map[f,0]);
   inc(map[t,0]);
   map[f,map[f,0]]:=t;
   map[t,map[t,0]]:=f;
  end;
 ans:=100000;
 for i:=1 to map[m,0] do
  if (ans>map[m,0]) and (dfs(map[m,i],-1)=1)
   then
    ans:=map[m,0];
 if (ans<10000)
  then
   writeln('First player wins flying to airport ',ans)
  else
   writeln('First player loses');
end.


end.
