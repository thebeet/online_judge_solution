var
 i,n,m,t:longint;
begin
 read(n);
 for i:=1 to n do
  begin
   read(m);
   if (m>10)
    then
     begin
      dec(m);
      t:=trunc(sqrt(m));
      if (t*(t+1)=m) then writeln('1') else writeln('0');
     end
    else
     if ((m=1) or (m=2) or (m=4) or (m=7))
      then
       write('1 ')
      else
       write('0 ');
  end;
end.

