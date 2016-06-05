var
 i,p,n,m,pm:longint;
 chs:array [0..10000] of char;
 ch:char;
begin
 fillchar(chs,sizeof(chs),' ');
 p:=0;pm:=0;
 while (not eof) do
  begin
   read(ch);
   if ch='>' then if (p<pm) then inc(p);
   if ch='<' then if (p>0) then dec(p);
   if ((ch<>'>') and (ch<>'<') and (ord(ch)>20)) then begin
   inc(p);
   chs[p]:=ch;
   if (pm<p) then pm:=p;
   end;
  end;
 for i:=1 to pm do
  write(chs[i]);
 writeln;
end.

