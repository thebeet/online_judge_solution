var n:integer; i:integer;
begin
readln(n);
if n=0 then writeln(0) else begin
writeln('0'); writeln('X'); writeln('*');
for i:=1 to n-1 do begin
writeln(i); writeln('+');
writeln('X'); writeln('*'); end;
writeln(n); writeln('+'); end;
end.
