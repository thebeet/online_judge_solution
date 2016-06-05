var
 n,m:longint;
begin
 read(n,m);
 if (((n mod 3)=0) or ((m mod 3)=0)) then writeln('2')
                                      else writeln('1');
end.