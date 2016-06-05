var
 st,i,n,s:longint;
 ch:char;
begin
 st:=0;
 s:=0;
 while (not eof) do
  begin
   read(ch);
   if ((st=0) and (ch in ['A'..'Z']))
    then
     begin
      st:=1;
      Continue;
     end;
   if ((st=0) and (ch in ['a'..'z']))
    then
     begin
      inc(s);
      st:=1;
      Continue;
     end;
   if ((st=1) and (ch in ['A'..'Z']))
    then
     begin
      inc(s);
      Continue;
     end;
   if ((ch='.') or (ch='.') or (ch='.'))
    then
     begin
      st:=0;
      Continue;
     end;
  end;
 writeln(s);
end.
