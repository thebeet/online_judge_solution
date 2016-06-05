var
 i,p,n,m,pm,ln:longint;
 chs:array [0..100000] of char;
 ch:char;
begin
 fillchar(chs,sizeof(chs),' ');
 p:=0;pm:=80;
 while (not eof) do
  begin
   read(ch);
   if ch='>' then if (p<pm) then inc(p);
   if ch='<' then if (p>0) then dec(p);
   if ((ch<>'>') and (ch<>'<')) then begin
   inc(p);
   chs[p]:=ch;
   if (pm<p) then pm:=p;
   end;
  end;
 ln:=1;
 for i:=1 to pm do
  begin
   if ln>80 then begin ln:=1;writeln;end;
   write(chs[i]);
  end;
 writeln;
end.

