var
 i,pos,rob,n,m,t:longint;
 bus,tt:array [0..100] of longint;
procedure moni_rob;
 var
  i:longint;
 begin
  for i:=1 to rob do
   inc(tt[rob]);
  if ((tt[rob] mod bus[rob])=0)
   then
    begin
     inc(rob);
    end;
 end;
procedure moni_pos;
 var
  i:longint;
 begin
  for i:=1 to rob do
   inc(tt[rob]);
  if ((tt[pos] mod bus[pos])=0)
   then
    inc(pos);
 end;
begin
 read(m,n);
 for i:=1 to n do
  read(bus[i]);
 fillchar(tt,sizeof(tt),0);
 rob:=1;pos:=1;t:=0;
 for i:=1 to m do
  begin
   moni_rob;
   if rob>n then begin writeln('NO');exit;end;
  end;
 while ((rob<=n) and (rob<>pos)) do
  begin
   inc(t);
   moni_rob;
   moni_pos;
  end;
 if rob>n then writeln('NO') else writeln('YES');
end.
