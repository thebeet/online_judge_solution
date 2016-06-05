var
m:string[200];
d,i,c,z:byte;
bledy:longint;
zdanienowe,nowywyraz:byte;
procedure sprawdz;

begin
d:=length(m);
i:=0;
while i<d do
begin
inc(i);
if (ord(m[i])=46)or(ord(m[i])=33)or(ord(m[i])=63) 
then zdanienowe:=1
else if (ord(m[i])=0)or(ord(m[i])=32) then
begin
nowywyraz:=1;
c:=1
end
else if (ord(m[i])>63)and(ord(m[i])<91)or(ord(m[i])
<123)and(ord(m[i])>96)then

begin

if (zdanienowe=1) then
begin
if (ord(m[i])<123)and(ord(m[i])>96) then inc(bledy);
zdanienowe:=0;
end
else if nowywyraz=1 then
begin
nowywyraz:=0;
c:=0
end
else if (ord(m[i])>63)and(ord(m[i])<91) then inc
(bledy);
end;
if c=0 then nowywyraz:=0;
end;
end;
begin
zdanienowe:=1;
readln(m);

while m<>''do
begin
nowywyraz:=1;
if m<>'' then sprawdz;
readln(m);
end;
writeln(bledy);
end. 