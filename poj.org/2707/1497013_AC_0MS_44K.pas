var
  a,b,c,d,t1,t2,t3,t4:longint;

begin
  readln(a,b,c,d);
  while ((a<>0) and (b<>0) and (c<>0) and (d<>0)) do
    begin
      if ((a<=c) and (b<=d)) then begin writeln('100%');readln(a,b,c,d);continue;end;
      if ((a<=d) and (b<=c)) then begin writeln('100%');readln(a,b,c,d);continue;end;
      t1:=(c*100) div a;
      t2:=(d*100) div b;
      if t1>t2 then t1:=t2;
      t3:=(c*100) div b;
      t4:=(d*100) div a;
      if t3>t4 then t3:=t4;
      if t1<t3 then t1:=t3;
      writeln(t1,'%');
      readln(a,b,c,d);
    end;
end.
