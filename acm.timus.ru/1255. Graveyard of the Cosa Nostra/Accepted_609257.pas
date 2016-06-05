var
 n,k,s:longint;
begin
 read(n,k);
 if (n<k) then writeln('0')
          else
          if (n mod k*2-k<0) then writeln(n div k*(n+n mod k))
                             else writeln(n div k*(n+n mod k)+n mod k*2-k);
end.

