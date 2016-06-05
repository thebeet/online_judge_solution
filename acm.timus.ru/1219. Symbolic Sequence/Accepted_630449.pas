var
i:longint;
begin
randomize;
for i:=1 to 1000000do
write(chr(random(26)+ord('a')));
writeln;
end.
