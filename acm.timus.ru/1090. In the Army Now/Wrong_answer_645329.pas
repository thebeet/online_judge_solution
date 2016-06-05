type
 numtre=array [0..70000] of longint;
var
 tt:numtre;
 i,j,n,m,mm,pp,ss,k,t:longint;
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
 readln(n,k);
 mm:=-1;
 for i:=1 to k do
  begin
   ss:=0;
   for j:=1 to n do
    begin
     read(t);
     ss:=ss+readtree(t);
     addtree(t);
    end;
   if ss>mm then begin mm:=ss;pp:=i;end;
  end;
 writeln(pp);
end.