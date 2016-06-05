var
 LC:set of 'A'..'Z';
 ls:set of 'a'..'z';
 i,n,m,p:longint;
 ch:char;
 chs:array [0..1000] of char;
begin
 lc:=['A'..'Z'];
 ls:=['a'..'z'];
 p:=0;
 while (not eof) do
  begin
   read(ch);
   if ((ch in lc) or (ch in ls))
    then
     begin
      inc(p);
      chs[p]:=ch;
     end
    else
     begin
      for i:=p downto 1 do
       write(chs[i]);
      write(ch);
      p:=0;
     end;
  end;
 for i:=p downto 1 do
  write(chs[i]);
end.
