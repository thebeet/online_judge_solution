var
 n,k,s:longint;
begin
 read(n,k);
 if (n<k) then writeln('0')
          else
           begin
            s:=n;
            s:=s+(n div k)*(n-k);
            writeln(s);
           end;
end.

