type
 numtree=array [0..68000] of longint;
var
 i,n,m,x,y:longint;
 tt:numtree;
 ans:array [0..20000] of longint;
function readtree(p:longint):longint;
 var
  s:longint;
 begin
  s:=0;
  p:=32768+p;
  while (p<>0) do
   begin
    s:=s+tt[p];
    p:=p shr 1;
   end;
  readtree:=s;
 end;
procedure addtree(p:longint);
 var
  k,t,bin2:longint;
 begin
  inc(tt[1]);
  t:=p+32767;
  while (p>0) do
   begin
    bin2:=p mod 2;
    if (bin2=1)
     then
      dec(tt[t]);
    p:=p shr 1;
    t:=(t-1) shr 1;
   end;
 end;
begin
 fillchar(tt,sizeof(tt),0);
 fillchar(ans,sizeof(ans),0);
 readln(n);
 for i:=1 to n do
  begin
   readln(x);
   inc(ans[readtree(x)]);
   addtree(x);
  end;
 for i:=0 to (n-1) do
  writeln(ans[i]);
end.




