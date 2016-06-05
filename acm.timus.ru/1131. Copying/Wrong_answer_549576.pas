var
 n,k,s,i,t:longint;
begin
 readln(n,k);
 i:=0;s:=0;t:=0;
 while (s<n) do
  begin
   inc(i);
   inc(t);
   if (i>k) then dec(i);
   s:=s+i;
  end;
 writeln(t);
end.