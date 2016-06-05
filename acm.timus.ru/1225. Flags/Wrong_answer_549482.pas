var
 n,a,b,m,t,i:longint;
begin
 readln(n);
 a:=2;
 b:=2;
 t:=0;
 if (n<3) then begin writeln('2');exit;end
          else
           for i:=3 to n do
           begin
            t:=a;
            a:=a+b;
            b:=t;
           end;
 writeln(a);
end.