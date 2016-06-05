var
 i,n,m,t,sum:longint;
 tlist:array [0..15000] of longint;
function ex(t:longint):boolean;
 var
  i,f:longint;
  flag:boolean;
 begin
  flag:=true;
  i:=(n div 2);
  f:=((n+1) div 2);
  while (tlist[i]<>t) do
   begin
    if f=0 then begin flag:=false;break;end;
    if (tlist[i]>t)
     then
      begin
       f:=((f+1) div 2);
       i:=i-f;
      end
     else
      begin
       f:=((f+1) div 2);
       i:=i+f;
      end;
    if ((i<1) or (i>n)) then begin flag:=false;break;end;
   end;
  ex:=flag;
 end;
begin
 read(n);
 for i:=1 to n do
  read(tlist[i]);
 read(m);
 sum:=0;
 for i:=1 to m do
  begin
   read(t);
   if ex(t) then inc(sum);
  end;
 writeln(sum);
end.
