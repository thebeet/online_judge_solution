var
 i,p,n,m,pm:longint;
 chs:array [0..100000] of char;
 ch:char;
begin
 fillchar(chs,sizeof(chs),' ');
 p:=0;pm:=0;
 while (not eof) do
  begin
   read(ch);
   if ch='>' then inc(p);
   if ch='<' then dec(p);
   if ((ch<>'>') and (ch<>'<')) then begin
   inc(p);
   chs[p]:=ch;
   if (pm<p) then pm:=p;
   end;
  end;
 for i:=1 to pm do
  write(chs[i]);
 writeln;
end.

