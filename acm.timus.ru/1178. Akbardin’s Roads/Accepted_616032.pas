const
  Max = 10000;
type
  rr=record
      n,id:longint;
     end;
  List = array[1..Max] of rr;
var
  Data: List;
  I,n: longint;
procedure QuickSort(var A: List; Lo, Hi: longint);
procedure Sort(l, r: longint);
var
  i, j, x: longint;
  y:rr;
begin
  i := l; j := r; x := a[(l+r) shr 1].n;
  repeat
    while a[i].n < x do i := i + 1;
    while x < a[j].n do j := j - 1;
    if i <= j then
    begin
      y := a[i]; a[i] := a[j]; a[j] := y;
      i := i + 1; j := j - 1;
    end;
  until i > j;
  if l < j then Sort(l, j);
  if i < r then Sort(i, r);
end;
begin {QuickSort};
  Sort(Lo,Hi);
end;
begin {QSort}
  read(n);
  for i := 1 to n do
   begin
    readln(Data[i].n);
    data[i].id:=i;
   end;
  QuickSort(Data, 1, n);
  for i:=1 to (n shr 1) do
   writeln(data[2*i-1].id,' ',data[2*i].id);

end.
