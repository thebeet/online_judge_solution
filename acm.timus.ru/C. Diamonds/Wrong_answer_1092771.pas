var
  d1,d2:string;
  v1,v2:longint;
  n,i,l:longint;

begin
  readln(d1);
  readln(d2);
  v1:=0;v2:=0;
  for i:=1 to 4 do
    begin
      if d1[i]='R' then v1:=v1+1;
      if d1[i]='G' then v1:=v1+5;
      if d1[i]='B' then v1:=v1+25;
      if d1[i]='Y' then v1:=v1+125;
      if d2[i]='R' then v2:=v2+1;
      if d2[i]='G' then v2:=v2+5;
      if d2[i]='B' then v2:=v2+25;
      if d2[i]='Y' then v2:=v2+125;
    end;
  if (v1<>v2) then writeln('different')
              else writeln('equal');
end.


