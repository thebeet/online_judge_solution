var
 n,k,s,i,t:longint;
begin
 readln(n,k);
 i:=1;s:=1;t:=0;
 while (s<n) do
  begin
   inc(t);
   if (i>k) then i:=k;
   s:=s+i;
   inc(i);
  end;
 writeln(t);
end.
