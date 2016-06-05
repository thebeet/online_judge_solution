var
 i,p,n,m,pm,ln:longint;
 chs:array [0..100000] of char;
 ch:char;
begin
 fillchar(chs,sizeof(chs),' ');
 p:=0;
 while (not eof) do
  begin
   read(ch);
   if ch='>' then begin inc(p);if p=81 then p:=0;end;
   if ch='<' then if (p>0) then dec(p) else p:=80;
   if ((ch<>'>') and (ch<>'<') and (ord(ch)>15)) then begin
   inc(p);
   if p=81 then p:=1;
   chs[p]:=ch;
   end;
  end;
 for i:=1 to 80 do
  begin
   write(chs[i]);
 end;
 writeln;
end.

