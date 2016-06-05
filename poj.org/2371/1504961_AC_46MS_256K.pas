var
 i,n,m,j,k:longint;
 sl:array [0..100000] of integer;
 js:array [0..5000] of longint;
begin
 read(n);
 fillchar(j,sizeof(j),0);
 for i:=1 to n do
  begin
   read(sl[i]);
   inc(js[sl[i]]);
  end;
 k:=0;
 for i:=1 to 5000 do
  for j:=1 to js[i] do
   begin
    inc(k);
    sl[k]:=i;
   end;
 readln;
 readln;
 read(n);
 for i:=1 to n do
  begin
   read(m);
   writeln(sl[m]);
  end;
end.

