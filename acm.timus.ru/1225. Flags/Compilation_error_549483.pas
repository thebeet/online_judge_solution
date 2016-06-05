var
 n,a,b,m,t,i:int64;
begin
 readln(n);
 a:=2;
 b:=2;
 if (n<3) then begin writeln('2');end
          else
           for i:=3 to n do
           begin
            t:=a;
            a:=a+b;
            b:=t;
           end;
 writeln(a);
end.