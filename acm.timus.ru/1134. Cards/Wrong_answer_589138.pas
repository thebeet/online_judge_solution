var
 i,n,m,t:longint;
 flag:boolean;
 num:array [0..1000] of boolean;
begin
 fillchar(num,sizeof(num),false);
 read(n,m);
 flag:=true;
 for i:=1 to m do
  begin
   read(t);
   if (t<1) then t:=-t+1;
   if num[t]=true then begin flag:=false;break;end;
   num[t]:=true;
  end;
 if flag then writeln('YES')
         else writeln('NO');
end.

