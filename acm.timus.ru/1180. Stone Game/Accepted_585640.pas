var
 i,n,s,t:longint;
 ch:char;
begin
 s:=0;
 while (not eof) do
  begin
   read(ch);
   if (ord(ch)>20) then begin
   t:=(ord(ch)-48) mod 10;
   s:=(s*10+t) mod 3;
   end;
  end;
 if s=0 then writeln('2')
        else
         begin
          writeln('1');
          writeln(s);
         end;
end.
