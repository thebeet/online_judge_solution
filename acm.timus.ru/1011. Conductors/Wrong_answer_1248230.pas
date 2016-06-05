var
  i,na,nb,nna,nnb:longint;
  a,b:double;

begin
  read(a,b);
  na:=trunc((a+0.001)*100);
  nb:=trunc((b+0.001)*100);
  i:=1;
  while true do
    begin
      nna:=i*na;
      nnb:=i*nb;
      if ((nna+1) div 10000)<(nnb div 10000) then break;
      inc(i);
    end;
  writeln(i);
end.