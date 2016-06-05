var
 s3,n,i,p:longint;
 s1,s2,m:double;
function myabs(n:double):double;
 begin
  if (n<0) then myabs:=(-n) else myabs:=n;
 end;
begin
 read(n);
 read(s1);
 m:=-1;
 p:=2;
 for i:=2 to n do
  begin
   read(s2);
   if ((myabs(s2-s1))>m) then begin m:=myabs(s2-s1);p:=i;end;
   s1:=s2;
  end;
 writeln(p-1,' ',p);
end.