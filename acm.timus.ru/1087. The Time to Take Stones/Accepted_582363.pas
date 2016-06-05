var
 win:array [0..10000] of boolean;
 i,n,m,j:longint;
 way:array [0..50] of longint;
begin
 fillchar(win,sizeof(win),false);
 read(n,m);
 win[0]:=true;
 for i:=1 to m do
  read(way[i]);
 for i:=1 to n do
  for j:=1 to m do
   if (((i-way[j])>=0) and (not win[i-way[j]])) then begin win[i]:=true;break;end;
 if win[n] then writeln('1')
           else writeln('2');
end.
