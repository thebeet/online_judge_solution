var
 st,i,n,s,w:longint;
 ch:char;
begin
 st:=0;
 s:=0;
 w:=0;
 while (not eof) do
  begin
   read(ch);
   if (not ((ch in ['A'..'Z']) or (ch in ['a'..'z']))) then w:=0;
   if ((st=0) and (ch in ['A'..'Z']))
    then
     begin
      st:=1;
      w:=1;
      Continue;
     end;
   if ((st=0) and (ch in ['a'..'z']))
    then
     begin
      inc(s);
      st:=1;
      w:=1;
      Continue;
     end;
   if ((st=1) and (w=0) and (ch in ['A'..'Z']))
    then
     begin
      inc(s);
      w:=1;
      Continue;
     end;
   if ((ch='.') or (ch='!') or (ch='?') or (ord(ch)=10))
    then
     begin
      st:=0;
      w:=0;
      Continue;
     end;
  end;
 writeln(s);
end.
