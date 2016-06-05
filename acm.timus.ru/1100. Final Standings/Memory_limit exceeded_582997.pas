type
 team=record
       id:longint;
       pn:byte;
      end;
var
 i,n,m,k,h:longint;
 ss,ss1:array [0..150000] of team;
 j,s,p:array [0..100] of longint;
begin
 fillchar(ss,sizeof(ss),0);
 fillchar(j,sizeof(j),0);
 fillchar(p,sizeof(p),0);
 fillchar(s,sizeof(s),0);
 read(n);
 for i:=1 to n do
  read(ss[i].id,ss[i].pn);
 for i:=1 to n do
  inc(j[ss[i].pn]);
 k:=0;
 s[1]:=0;
 for i:=2 to 100 do
  s[i]:=s[i-1]+j[i-1];
 for i:=1 to n do
  begin
   inc(p[ss[i].pn]);
   ss1[s[ss[i].pn]+p[ss[i].pn]]:=ss[i];
  end;
 for i:=n downto 1 do
  writeln(ss1[i].id,' ',ss1[i].pn);
end.