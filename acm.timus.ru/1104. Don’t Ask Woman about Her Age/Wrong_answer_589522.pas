var
 remain: array[2..36]of longint;
 p: char;
 i, num, max: integer;
begin
 fillchar(remain, sizeof(remain), 0);
 max := 0;
 while not eof do
  begin
   read(p);
   if p in ['0'..'9'] then num := (ord(p) - 48) mod 10 else
   if p in ['A'..'Z'] then num := ord(p) - ord('A') + 10
   else continue;
   if num > max then max := num;
   for i := 2 to 36 do
   remain[i] := (remain[i] * i + num) mod (i - 1);
  end;
 for i :=(max + 1) to 36 do
  if remain[i] = 0 then
   break;
 if remain[i] = 0 then
  writeln(i) else writeln('No solution.');
end.