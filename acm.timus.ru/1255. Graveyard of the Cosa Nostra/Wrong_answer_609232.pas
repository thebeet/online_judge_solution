var
 n,k,s:longint;
begin
 read(n,k);
 if (n<k) then writeln('0')
          else
           if (((n*n mod k)=0) and ((n mod k)>0)) then writeln((n*n-k) div k)
                                                 else writeln(n*n div k);
end.

