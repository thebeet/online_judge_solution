var
 i,n:longint;
 m,t:int64;
begin
 read(n);
 for i:=1 to n do
  begin
   read(m);
   if (m>10)
    then
     begin
      dec(m);
      t:=trunc(sqrt(m*2));
      if (t*(t+1)=2*m) then write('1 ') else write('0 ');
     end
    else
     if ((m=1) or (m=2) or (m=4) or (m=7))
      then
       write('1 ')
      else
       write('0 ');
  end;
end.

