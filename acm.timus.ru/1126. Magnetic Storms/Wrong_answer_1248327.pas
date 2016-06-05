type
  data=record
         n:longint;
         p:longint;
       end;
  dui=array [0..14001] of data;


var
  i,n,m,l:longint;
  a:array [0..25001] of data;
  td:dui;

procedure QSort(var A: dui; L, r: longint);
var
  i, j, x, y: longint;
  t:data;
begin
  i := l; j := r; x := a[(l+r) DIV 2].n;
  repeat
    while a[i].n > x do inc(i);
    while x > a[j].n do dec(j);
    if i <= j then
    begin
      t := a[i]; a[i] := a[j]; a[j] := t;
      i := i + 1; j := j - 1;
    end;
  until i > j;
  if l < j then qSort(a,l, j);
  if i < r then qSort(a,i, r);
end;

procedure swap(p1,p2:longint);
  var
    t:longint;
    da:data;
  begin
    da:=td[p1];
    td[p1]:=td[p2];
    td[p2]:=da;
    t:=a[td[p1].p].p;
    a[td[p1].p].p:=a[td[p2].p].p;
    a[td[p2].p].p:=t;
  end;

procedure check_up(p:longint);
  begin
    if (p>1) and (td[p].n>td[p div 2].n) then begin swap(p,p div 2);check_up(p div 2);end;
  end;

procedure check_down(p:longint);
  var
    p2:longint;
  begin
    p2:=p;
    if (p*2<=m) and (td[p*2].n>td[p].n) then p2:=p*2;
    if (p*2+1<=m) and (td[p*2+1].n>td[p2].n) then p2:=p*2+1;
    if (p2<>p) then begin swap(p,p2);check_up(p2);end;
  end;


procedure check(p:longint);
  begin
    check_up(p);
    check_down(p);
  end;


begin
  readln(m);
  for i:=1 to m do
    begin
      readln(a[i].n);
      td[i].p:=i;
      td[i].n:=a[i].n;
    end;
  qsort(td,1,m);
  for i:=1 to m do
    a[td[i].p].p:=i;
  i:=m+1;
  while true do
    begin
      writeln(td[1].n);
      readln(a[i].n);
      if (a[i].n<0) then break;
      a[i].p:=a[i-m].p;
      td[a[i].p].p:=i;
      td[a[i].p].n:=a[i].n;
      check(a[i].p);
      inc(i);
    end;
end.