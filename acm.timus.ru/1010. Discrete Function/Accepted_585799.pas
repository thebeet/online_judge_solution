var
 s3,n,i,p:longint;
 s1,s2,m:double;
function myabs(n:double):double;
 begin
  if (n<0) then myabs:=-n else myabs:=n;
 end;
begin
 read(n);
 read(s1);
 m:=-1;
 p:=2;
 for i:=1 to (n-1) do
  begin
   read(s2);
   if ((myabs(s1-s2))>m) then begin m:=myabs(s1-s2);p:=i;end;
   s1:=s2;
  end;
 writeln(p,' ',p+1);
end.