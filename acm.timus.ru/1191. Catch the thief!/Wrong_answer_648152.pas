var
 i,pos,rob,n,m,t:longint;
 bus:array [0..100] of longint;
procedure moni_rob(t:longint);
 var
  i:longint;
 begin
  if ((t mod bus[rob])=0)
   then
   inc(rob);
 end;
procedure moni_pos(t:longint);
 var
  i:longint;
 begin
  if ((t mod bus[pos])=0)
   then
   inc(pos);
 end;
begin
 read(m,n);
 for i:=1 to n do
  read(bus[i]);
 rob:=1;pos:=1;t:=0;
 for i:=1 to m do
  begin
   inc(t);
   moni_rob(t);
  end;
 while ((rob<=n) and (rob<>pos)) do
  begin
   inc(t);
   moni_rob(t);
   moni_pos(t);
  end;
 if rob>n then writeln('YES') else writeln('NO');
end.
