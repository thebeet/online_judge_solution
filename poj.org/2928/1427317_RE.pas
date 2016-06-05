var
  i,n,l,m,h,pt,c1,c2,t,g1,g2:longint;
  ccm,ccn:longint;
  a,s,b:array [0..100] of longint;

procedure Sort(l, r: longInt);
var
  i, j, x, y: longint;
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
procedure Sortb(l, r: longInt);
var
  i, j, x, y: longint;
begin
  i := l; j := r; x := b[(l+r) DIV 2];
  repeat
    while b[i] < x do i := i + 1;
    while x < b[j] do j := j - 1;
    if i <= j then
    begin
      y := b[i]; b[i] := b[j]; b[j] := y;
      i := i + 1; j := j - 1;
    end;
  until i > j;
  if l < j then Sortb(l, j);
  if i < r then Sortb(i, r);
end;

begin
  readln(n,m,c1,c2);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(s,sizeof(s),0);
  s[0]:=0;
  for i:=1 to n do
    readln(a[i]);
  sort(1,n);
  for i:=1 to n do
    s[i]:=s[i-1]+a[i];
  for i:=1 to m do
    readln(b[i]);
  sortb(1,m);
  ccn:=0;
  ccm:=0;
  t:=1;
  pt:=t;
  if (b[m]<>a[n]) then begin writeln('Impossible');exit;end;
  g1:=0;
  i:=n;
  while (a[i]=a[n]) and (i>0) do
    begin
      inc(g1);
      dec(i);
    end;
  i:=m;
  g2:=0;
  while (b[i]=b[m]) and (i>0) do
    begin
      inc(g2);
      dec(i);
    end;
  for i:=1 to m do
    begin
      while (a[t]<b[i]) do
        inc(t);
      ccm:=ccm+s[t-1]+(n-t+1)*b[i];
      if ((a[pt]=b[i-1]) and (pt<>t)) then ccn:=ccn-a[pt];
      ccn:=ccn+s[t-1]-s[pt-1]+b[i];
      pt:=t;
    end;
  if (g1>g2) then ccn:=ccn+(g1-g2)*a[n];
  ccn:=ccn*c1;
  ccm:=ccm*c2;
  writeln('Minimum: ',ccn,', maximum: ',ccm);
end.
