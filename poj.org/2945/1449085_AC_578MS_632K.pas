var
  i,n,m,l:longint;
  a:array [0..20001] of string[25];
  ans:array [0..20001] of longint;

procedure Sort(l, r: longInt);
var
  i, j: longint;
  x,y:string[25];
begin
  i := l; j := r; x := a[(l+r) DIV 2];
  repeat
    while a[i] < x do i := i + 1;
    while x < a[j] do j := j - 1;
    if i <= j then
    begin
      y := a[i]; a[i] := a[j]; a[j] := y;
      i := i + 1; j := j - 1;
    end;
  until i > j;
  if l < j then Sort(l, j);
  if i < r then Sort(i, r);
end;
begin
  readln(n,m);
  while (n>0) do
  begin
  for i:=1 to n do
    readln(a[i]);
  sort(1,n);
  fillchar(ans,sizeof(ans),0);
  m:=0;
  for i:=2 to n do
    if (a[i]<>a[i-1])
      then
        begin
          if (m>0) then
            begin
              inc(ans[m]);
              m:=0;
            end;
        end
      else
        inc(m);
  if (m>0) then inc(ans[m]);
  ans[0]:=n;
  for i:=1 to n do
    ans[0]:=ans[0]-(i+1)*ans[i];
  for i:=0 to (n-1) do
    writeln(ans[i]);
  readln(n,m);
  end;
end.
