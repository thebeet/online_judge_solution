const
  s1='Slytherin';
  s2='Hufflepuff';
  s3='Gryffindor';
  s4='Ravenclaw';

var
  a:array [1..4,0..1000] of string;
  nn:array [0..4] of longint;
  name,s:string;
  i,n,j:longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(name);
      readln(s);
      if s=s1 then begin inc(nn[1]);a[1,nn[1]]:=name;end;
      if s=s2 then begin inc(nn[2]);a[2,nn[2]]:=name;end;
      if s=s3 then begin inc(nn[3]);a[3,nn[3]]:=name;end;
      if s=s4 then begin inc(nn[4]);a[4,nn[4]]:=name;end;
    end;
  for i:=1 to 4 do
    begin
      if i=1 then writeln(s1+':');
      if i=2 then writeln(s2+':');
      if i=3 then writeln(s3+':');
      if i=4 then writeln(s4+':');
      for j:=1 to nn[i] do
        writeln(a[i,j]);
      if i<4 then writeln;
    end;
end.
