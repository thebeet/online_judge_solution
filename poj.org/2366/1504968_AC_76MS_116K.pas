var
 i,n,t,m:longint;
 nn:array [0..75000] of boolean;
 flag:boolean;
begin
 read(n);
 fillchar(nn,sizeof(nn),false);
 for i:=1 to n do
  begin
   read(t);
   if ((t+25000)>0) then nn[t+25000]:=true;
  end;
 read(n);
 flag:=false;
 for i:=1 to n do
  begin
   read(t);
   if nn[35000-t] then begin flag:=true;break;end;
  end;
 if flag then writeln('YES')
         else writeln('NO');
end.
