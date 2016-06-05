const a:array[2..10]of longint=
(3,13,75,541,4683,47293,545835,7087261,102247563);
var n:integer;
begin
readln(n);
while n<>-1 do begin writeln(a[n]);read(n);end;
end.
