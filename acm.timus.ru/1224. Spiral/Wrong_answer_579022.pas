var
 n,m:longint;
begin
 read(n,m);
 if n>=m then writeln(2*(m-1))
        else writeln(2*n-1);
end.