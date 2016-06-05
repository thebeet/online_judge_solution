var
  d1,d2:string;
  dd1,dd2:array [0..10] of longint;
  v1,v2,vv1,vv2:longint;
  n,i,j:longint;

begin
  readln(d1);
  readln(d2);
  v1:=0;v2:=0;
  for i:=1 to 4 do
    begin
      if d1[i]='R' then dd1[i]:=1;
      if d1[i]='G' then dd1[i]:=5;
      if d1[i]='B' then dd1[i]:=25;
      if d1[i]='Y' then dd1[i]:=125;
      if d2[i]='R' then dd2[i]:=1;
      if d2[i]='G' then dd2[i]:=5;
      if d2[i]='B' then dd2[i]:=25;
      if d2[i]='Y' then dd2[i]:=125;
      v1:=v1+dd1[i];
      v2:=v2+dd2[i];
    end;
  if (v1<>v2) then writeln('different')
              else if v1=156 then
                               begin
                                 vv1:=0;vv2:=0;
                                 for i:=2 to 4 do
                                   for j:=1 to (i-1) do
                                     begin
                                       if dd1[i]>dd1[j] then inc(vv1);
                                       if dd2[i]>dd2[j] then inc(vv2);
                                     end;
                                 if ((vv1 mod 2)=(vv2 mod 2)) then writeln('equal')
                                            else writeln('different');
                               end;
end.


