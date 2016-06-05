var
  i,n,m1,m2:longint;
  a:array [0..250000] of longint;

procedure QSort(l, r: longint);
var
  i, j, x, y: longint;
begin
  i := l; j := r; x := a[(l+r) shr 1];
  repeat
    while a[i] < x do inc(i);
    while x < a[j] do dec(j);
    if i <= j then
    begin
      y := a[i]; a[i] := a[j]; a[j] := y;
      inc(i);dec(j);
    end;
  until i > j;
  if (l < j) and (j>=m1) then qSort(l, j);
  if (i < r) and (i<=m2) then qSort(i, r);
end;

begin
  readln(n);
  for i:=1 to n do
    readln(a[i]);
  m1:=(n+1) div 2;
  m2:=(n+2) div 2;
  qsort(1,n);
  write((a[m1]+a[m2]) shr 1);
  if (((a[m1]+a[m2]) mod 2)=1) then write('.5');
  writeln;
end.