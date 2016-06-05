var
 i,n,m,s,s1:longint;
 ch:char;
begin
 s:=0;
 m:=-1;
 while not eof do
  begin
   read(ch);
   if (ch in ['0'..'9'])
    then
     s1:=s+((ord(ch)-48) mod 10)
    else
     if (ch in ['A'..'Z'])
      then
       s1:=s+ord(ch)-55;
   if (m<(s1-s)) then m:=s1-s;
   s:=s1;
  end;
 if (s=0) then begin writeln('2');exit;end;
 for i:=m to 35 do
  if ((s mod i)=0) then begin writeln(i+1);exit;end;
 writeln('No solution.');
end.

