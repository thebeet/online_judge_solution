type
 code=array [0..1000] of boolean;
var
 ls:code;
 i,n,m,l,t,k:longint;
 ch:char;
procedure out(thecode:code);
 var
  i:longint;
 begin
  for i:=1 to n do
   if thecode[i] then write('1') else write('0');
  writeln;
 end;
function ch1(tc:code;rm:longint):boolean;
 var
  i,s:longint;
 begin
  s:=0;
  for i:=1 to (rm-1) do
   if tc[i] then s:=s+i;
  for i:=(rm+1) to (n+1) do
   if tc[i] then s:=s+i-1;
  if ((s mod (n+1))=0)
   then
    begin
     for i:=1 to (n+1) do
      if (i<>rm) then
       if tc[i] then write('1') else write('0');
     writeln;
     ch1:=true;
     exit;
    end;
  ch1:=false;
 end;
function ch2(tc:code;ins,p:longint):boolean;
 var
  i,s:longint;
 begin
  s:=0;
  for i:=1 to (ins-1) do
   if tc[i] then s:=s+i;
  if p=1 then s:=s+ins;
  for i:=ins to n do
   if tc[i] then s:=s+i+1;
  if ((s mod (n+1))=0)
   then
    begin
     for i:=1 to (ins-1) do
     if tc[i] then write('1') else write('0');
     if p=1 then write('1');
     for i:=ins to n do
      if tc[i] then write('1') else write('0');
     writeln;
     ch2:=true;
     exit;
    end;
  ch2:=false;
 end;
procedure check(l:longint);
 var
  i,m,s,k:longint;
  lstmp:code;
 begin
  if (l=n)
   then
    begin
     s:=0;
     for i:=1 to l do
      if ls[i] then s:=s+i;
     if ((s mod (n+1))=0) then begin out(ls);exit;end;
     ls[s mod (n+1)]:=false;
     out(ls);
     exit;
    end;
  if (l-1=n)
   then
    for i:=1 to l do
     if ch1(ls,i) then exit;
  for i:=1 to n do
   for k:=0 to 1 do
    if ch2(ls,i,k) then exit;
 end;
begin
 read(n);
 k:=0;
 while not eof do
  begin
   read(ch);
   if ch='0' then begin inc(k);ls[k]:=false;end;
   if ch='1' then begin inc(k);ls[k]:=true ;end;
   if (((ord(ch)=10) or (ord(ch)=12)) and (abs(k-n)<2)) then begin check(k);k:=0;end;
  end;
end.
