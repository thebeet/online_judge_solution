var
 i,n,m,t:longint;
 ch:char;
begin
 readln(n);
 m:=0;t:=0;
 for i:=1 to n do
  begin
   read(ch);
   while not (ch in ['<','>']) do
    read(ch);
   if ch='<' then m:=m+t;
   if ch='>' then inc(t);
  end;
 writeln(m);
end.
