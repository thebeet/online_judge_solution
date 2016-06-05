var
 n,m:longint;
begin
 read(n,m);
 if ((n>1) and (m>1))
  then
   if (((n mod 3)=0) or ((m mod 3)=0)) then writeln('2')
                                       else writeln('1')
  else
   begin
    if n=1 then writeln((m+1) div 2)
           else writeln((n+1) div 2);
   end;
end.