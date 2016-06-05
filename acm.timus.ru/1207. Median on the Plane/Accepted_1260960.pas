type
  p=record
      x,y:longint;
    end;

var
  i,n,m,mp,d,mid,pp:longint;
  ps:array [0..10001] of p;
  id:array [0..10001] of longint;
  a:array [0..10001] of double;

procedure Sort(l, r: longInt);
var
  i, j, t:longint;
  x, y:double;
begin
  i := l; j := r; x := a[(l+r) DIV 2];
  repeat
    while a[i] < x do i := i + 1;
    while x < a[j] do j := j - 1;
    if i <= j then
    begin
      y := a[i]; a[i] := a[j]; a[j] := y;
      t:=id[i];  id[i]:=id[j]; id[j]:=t;
      i := i + 1; j := j - 1;
    end;
  until i > j;
  if (l < j) and (mid<=j) then Sort(l, j);
  if (i < r) and (mid>=i) then Sort(i, r);
end;

begin
  readln(n);
  m:=2000000000;
  for i:=1 to n do
    begin
      readln(ps[i].x,ps[i].y);
      if (ps[i].x<m) then
        begin
          m:=ps[i].x;
          pp:=i;
        end;
    end;
  d:=0;
  for i:=1 to (pp-1) do
    begin
      id[i]:=i;
      if (ps[i].x=ps[pp].x)
        then
          begin
            if (ps[i].y>ps[pp].y) then a[i]:=2000000000
                                 else a[i]:=-2000000000;
          end
        else
          a[i]:=(ps[i].y-ps[pp].y)/(ps[i].x-ps[pp].x);
    end;
  for i:=(pp+1) to n do
    begin
      id[i-1]:=i;
      if (ps[i].x=ps[pp].x)
        then
          begin
            if (ps[i].y>ps[pp].y) then a[i-1]:=2000000000
                                 else a[i-1]:=-2000000000;
          end
        else
          a[i-1]:=(ps[i].y-ps[pp].y)/(ps[i].x-ps[pp].x);
    end;
  mid:=n div 2;
  sort(1,n-1);
  writeln(pp,' ',id[mid]);
end.