var
 n,k,l,i :longint;
begin
 i:=0;
 readln(n,k);
 if k>n then l:=n-1
        else l:=k-1;
 while (l>=1) do
  begin
   inc(i);
   l:=l div 2;
  end;
 n:=n-(1 shl i);
 i:=i+ord((n mod k)>0)+(n div k);
 writeln(i);
end.

