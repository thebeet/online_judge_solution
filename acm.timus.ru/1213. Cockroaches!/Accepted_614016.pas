var
 map:array [0..30,0..30] of boolean;
 ps:array [0..30] of string;
 i,n,m,k,l,p,p1,p2:longint;
 str1,str2:string;
function find(str:string):longint;
 var
  i:longint;
 begin
  for i:=1 to n do
   if ps[i]=str then begin find:=i;exit;end;
  inc(n);
  ps[n]:=str;
  find:=n;
 end;
begin
 n:=1;
 readln(str1);
 ps[1]:=str1;
 readln(str1);
 while (str1<>'#') do
  begin
   p:=pos('-',str1);
   str2:=copy(str1,1,p-1);
   p1:=find(str2);
   str2:=copy(str1,p+1,length(str1)-p);
   p2:=find(str2);
   map[p1,p2]:=true;
   map[p2,p1]:=true;
   readln(str1);
  end;
 writeln(n-1);
end.
