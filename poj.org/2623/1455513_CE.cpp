type
  dui=array [0..125002] of longword;

var
  i,l:longint;
  td:dui;
  m,m1,m2,n:longword;

procedure QSort(l, r: longword);
var
  i, j: longint;
  x, y: longword;
begin
  i := l; j := r; x := td[(l+r) shr 1];
  repeat
    while td[i] > x do inc(i);
    while x > td[j] do dec(j);
    if i <= j then
    begin
      y := td[i]; td[i] := td[j]; td[j] := y;
      inc(i);dec(j);
    end;
  until i > j;
  if (l < j) then qSort(l, j);
  if (i < r) then qSort(i, r);
end;

procedure swap(p1,p2:longint);
  var
    da:longword;
  begin
    da:=td[p1];
    td[p1]:=td[p2];
    td[p2]:=da;
  end;

procedure check_down(p:longint);
  var
    p2:longint;
  begin
    p2:=p;
    if (p*2<=l) and (td[p*2]>td[p]) then p2:=p*2;
    if (p*2+1<=l) and (td[p*2+1]>td[p2]) then p2:=p*2+1;
    if (p2<>p) then begin swap(p,p2);check_down(p2);end;
  end;

begin
  {fillchar(a,sizeof(a),0);}
  readln(n);
  if n=1 then
    begin
      readln(m1);
      writeln(m1,'.0');
      exit;
    end;
  if n=2 then
    begin
      readln(m1);
      readln(m2);
      write((m1+m2) shr 1);
      if (((m1+m2) mod 2)=0) then writeln('.0') else writeln('.5');
      exit;
    end;
  l:=((n+4) div 2);
  for i:=1 to l do
    readln(td[i]);
  qsort(1,l);
  for i:=(l+1) to n do
    begin
      readln(m);
      td[1]:=m;
      check_down(1);
    end;
  swap(1,l);
  dec(l);
  check_down(1);
  m1:=td[1];
  if (n mod 2)=0 then
    begin
      swap(1,l);
      dec(l);
      check_down(1);
      m2:=td[1];
    end
    else
      m2:=m1;
  write((m1+m2) shr 1);
  if (((m1+m2) mod 2)=1) then write('.5') else write('.0');
  writeln;
end.