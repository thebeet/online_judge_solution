var
 n,a,b,m,t,i:longint;
begin
 readln(n);
 if (n<5) then n:=n div 0;
 a:=2;
 b:=2;
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