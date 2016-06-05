var
 i,n,m,s:longint;
 team:array [0..100] of byte;
begin
 read(n);
 fillchar(team,sizeof(team),0);
 s:=0;
 for i:=1 to n do
  begin
   if team[i]=0 then team[i]:=1;
   if team[i]=1 then inc(s);
   read(m);
   while (m<>0) do
    begin
     if team[m]=0 then team[m]:=-team[i];
     read(m);
    end;
  end;
 writeln(s);
 for i:=1 to n do
  if team[i]=1 then write(i,' ');
end.
