{$R+}
var
 i,pos,rob,n,m:longint;
 bus,tt:array [0..100] of longint;
procedure moni_rob;
 var
  i:longint;
 begin
  for i:=1 to rob do
   inc(tt[i]);
  if ((tt[rob] mod bus[rob])=0)
   then
    begin
     inc(rob);
    end;
 end;
procedure moni;
 var
  i:longint;
 begin
  for i:=pos to rob do
   inc(tt[i]);
  if ((tt[pos] mod bus[pos])=0)
   then
    inc(pos);
  if pos=rob then begin writeln('YES');exit;end;
  if ((tt[rob] mod bus[pos])=0)
   then
    inc(rob);
 end;
begin
 read(m,n);
 for i:=1 to n do
  read(bus[i]);
 fillchar(tt,sizeof(tt),0);
 rob:=1;pos:=1;
 for i:=1 to m do
  begin
   moni_rob;
   if rob>n then begin writeln('NO');exit;end;
  end;
 while ((rob<=n) and (rob<>pos)) do
  moni;
 if rob>n then writeln('NO') else writeln('YES');
end.
