var
 i,pos,rob,n,m,t:longint;
 bus:array [0..100] of longint;
procedure moni_rob(var t:longint);
 var
  i:longint;
 begin
  if ((t mod bus[rob])=0)
   then
    begin
     inc(rob);
     t:=0;
    end;
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
 if rob>n then writeln('NO') else writeln('YES');
end.
