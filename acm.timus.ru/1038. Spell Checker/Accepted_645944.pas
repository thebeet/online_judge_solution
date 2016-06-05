program spellchecker;
var ch:char;
state:integer;
errors:integer;
begin
state:=0;
errors:=0;
while not eof do begin
read(ch);
case state of
0: begin
if ch in ['a'..'z']
then inc(errors);
if ch in ['a'..'z']+['A'..'Z'] then state:=1;
end;
1: begin
if ch in ['A'..'Z'] then inc(errors);
if not (ch in ['a'..'z']+['A'..'Z']) then
if ch in ['.','!','?'] then state:=0 else state:=2;
end;
2: begin
if ch in ['a'..'z']+['A'..'Z'] then state:=1;
if ch in ['.','!','?'] then state:=0;
end;
end;
end;
writeln(errors);
end.