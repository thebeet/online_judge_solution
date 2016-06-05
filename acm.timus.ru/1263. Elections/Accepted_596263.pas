var
 i,n,m,s,t:longint;
 ans:array [0..10000] of real;
begin
 read(n,m);
 fillchar(ans,sizeof(ans),0);
 for i:=1 to m do
  begin
   read(t);
   ans[t]:=ans[t]+100;
  end;
 for i:=1 to n do
  writeln((ans[i]/m):0:2,'%');
end.
