const
 max=255;
type
 node=^stack;
 stack=record
        d:array [1..max] of longint;
        n:node;
       end;
var
 sk:array [1..1000] of node;
 nn:array [1..1000] of integer;
 i,n,m,a,b:longint;
 ch1,ch2:char;
procedure push(a,b:longint);
 var
  sss:node;
 begin
  inc(nn[a]);
  if nn[a]=256 then nn[a]:=1;
  if (nn[a]=1)
   then
    begin
     new(sss);
     sss^.d[1]:=b;
     sss^.n:=sk[a];
     sk[a]:=sss;
    end
   else
     sk[a]^.d[nn[a]]:=b;
 end;
function pop(a:longint):longint;
 var
  tmp:node;
 begin
  pop:=sk[a]^.d[nn[a]];
  dec(nn[a]);
  if nn[a]=0 then
  begin
  nn[a]:=255;
  tmp:=sk[a];
  sk[a]:=sk[a]^.n;
  dispose(tmp);
  end;
 end;
begin
 readln(n);
 for i:=1 to n do
  begin
   read(ch1,ch2);
   if (ch2='U')
    then
     begin
      read(ch1,ch2);
      readln(a,b);
      push(a,b);
     end
    else
     begin
      read(ch1);
      readln(a);
      writeln(pop(a));
     end;
  end;
end.