var
 a:array[0..500] of extended;
 n,i,j:longint;
begin
 read(n);
 fillchar(a,sizeof(a),0); a[0]:=1;
 for j:=1 to n do
  for i:=n downto j do
   a[i]:=a[i]+a[i-j];
 a[n]:=a[n]-1;
 writeln(a[n]:0:0);
end.
