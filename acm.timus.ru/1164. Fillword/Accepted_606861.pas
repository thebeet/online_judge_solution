var
Save : array ['A' .. 'Z'] of longint;
n, m, p, i, j : longint;
c : char;
begin
fillchar (Save, sizeof (Save), 0);
readln (n, m, p);
for i := 1 to n do
begin
for j := 1 to m do
begin
read (c);
Save [c] := Save [c] + 1;
end;
readln;
end;
for i := 1 to p do
begin
read (c);
while not (c in ['A' .. 'Z']) do
read (c);
while c in ['A' .. 'Z'] do
begin
Save [c] := Save [c] - 1;
read (c);
end;
end;
for c := 'A' to 'Z' do
for i := 1 to Save [c] do
write (c);
end. 