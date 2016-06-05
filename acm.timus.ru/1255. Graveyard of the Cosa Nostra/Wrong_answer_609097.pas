var
 n,k,s:longint;
begin
 read(n,k);
 if (n<k) then writeln('0')
          else writeln(n*n div k);
end.

