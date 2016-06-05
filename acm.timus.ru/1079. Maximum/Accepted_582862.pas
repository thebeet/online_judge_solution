var
 i,max,n,max1:longint;
 a:array [0..100000] of longint;
begin
 a[1]:=1;
 a[0]:=0;
 for i:=2 to 100000 do
  begin
   if i mod 2=0 then a[i]:=a[i shr 1]
   else a[i]:=a[i shr 1]+a[i shr 1+1];
  end;
 read(n);
 while (n<>0) do
  begin
   max1:=0;
   for i:=1 to n do
    if (max1<a[i]) then max1:=a[i];
   writeln(max1);
   read(n)
  end;
end.
