var
 s1,m,s2,s3,n,i,p:longint;
begin
 read(n);
 read(s1);
 m:=-1;
 p:=2;
 for i:=2 to n do
  begin
   read(s2);
   if ((abs(s2-s1))>m) then begin m:=abs(s2-s1);p:=i;end;
   s1:=s2;
  end;
 writeln(p-1,' ',p);
end.