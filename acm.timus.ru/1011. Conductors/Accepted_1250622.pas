var
  i,na,nb,nna,nnb:longint;
  a,b:double;

begin
  read(a,b);
  na:=trunc(a*100+0.1);
  nb:=trunc(b*100+0.1);
  i:=1;
  while true do
    begin
      nna:=i*na;
      nnb:=i*nb;
      if ((nna div 10000)<((nnb-1) div 10000)) then break;
      inc(i);
    end;
  writeln(i);
end.
