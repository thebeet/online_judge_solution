var
 a:array [0..100] of longint;
 i,n:longint;
begin
 a[1]:=1;
 a[2]:=1;
 a[3]:=2;
 read(n);
 for i:=3 to n do
  a[i]:=a[i-1]+a[i-3]+1;
 writeln(a[n]);
end.
