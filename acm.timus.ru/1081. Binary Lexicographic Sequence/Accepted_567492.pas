var
 i,j,t,n,k,a1,a2,a3:longint;
 ans:array [-2..50] of longint;
 ww:boolean;
begin
 fillchar(ans,sizeof(ans),0);
 read(n,k);
 j:=-1;
 ww:=false;
 while (j<>0) do
 begin
 a1:=1;
 a2:=0;
 j:=0;
 while (a1<k) do
  begin
   inc(j);
   a3:=a1;
   a1:=a1+a2;
   a2:=a3;
  end;
 ans[j-1]:=1;
 k:=k-a2;
 if ((j-1)>n) then ww:=true;
 end;
 if ww then write('-1') else
 for i:=n downto 1 do
  write(ans[i]);
 writeln;
end.