var
  i,n,m,l,n1,j:longint;
  flag:boolean;
  l1,ln:array [0..1001] of longint;

begin
  read(n);
  while (n>0) do
    begin
      flag:=true;
      for i:=1 to n do
        read(l1[i]);
      for i:=2 to n do
        begin
          read(n1);
          for j:=2 to n do
            begin
              read(l);
              if ((l1[1]+l)<>(l1[i]+n1)) then flag:=false;
            end;
        end;
      if flag then writeln('homogeneous')
              else writeln('not homogeneous');
      read(n);
    end;
end.

