type
 node=record
       d:integer;
       n:longint;
      end;
var
 dl:array [1..100000] of node;
 l,le:array [1..1000] of longint;
 able:array [1..1000] of integer;
 i,n,m,f,t,k:longint;
procedure insert(f,t:longint);
 begin
  if (l[f]=0)
   then
    begin
     inc(k);
     l[f]:=k;
     le[f]:=k;
     dl[k].d:=t;
    end
   else
    begin
     inc(k);
     dl[le[f]].n:=k;
     le[f]:=k;
     dl[k].d:=t;
    end;
 end;
procedure pop(f:longint);
 var
  tmp:longint;
 begin
  tmp:=l[f];
  while tmp<>0 do
   begin
    dec(able[dl[tmp].d]);
    tmp:=dl[tmp].n;
   end;
 end;
begin
 k:=0;
 read(n,m);
 for i:=1 to m do
  begin
   read(f,t);
   insert(f,t);
   inc(able[t]);
  end;
 for i:=1 to n do
  begin
   read(t);
   if (able[t]<>0) then begin writeln('NO');exit;end;
   pop(t);
  end;
 writeln('YES');
end.
