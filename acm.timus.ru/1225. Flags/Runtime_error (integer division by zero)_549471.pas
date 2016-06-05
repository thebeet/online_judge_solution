var
 n,a,b,m,t,i:longint;
begin
 readln(n);
 a:=2;
 b:=2;
 t:=0;
 if (n=1) then n:=n div t;
 if (n<3) then writeln('2')
          else
           for i:=3 to n do
           begin
            t:=a;
            a:=a+b;
            b:=t;
           end;
 writeln(a);
end.