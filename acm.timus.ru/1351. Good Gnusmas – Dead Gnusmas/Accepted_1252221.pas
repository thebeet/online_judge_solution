const
  mm=0.000000000001;
var
  i,n,d,x1,x2,y1,y2,x,y:longint;
  th1,th2,th:double;
  b1,b2:boolean;

function check(z1,m1,z2,m2:longint):longint;
  begin
    if ((z1*m2)>(z2*m1))
      then check:=1
      else
        if ((z1*m2)=(z2*m1))
          then check:=0
          else check:=-1;
  end;

function dr(x,y:longint):double;
  begin
    if (x>0) then exit(y/x);
    if ((y>0) and (x=0)) then exit(100001);
    if (x<0) then exit(300000+y/x);
    if ((y>0) and (x=0)) then exit(500001);
  end;


begin
  readln(d,x1,y1,x2,y2);
  th1:=dr(x1,y1);
  th2:=dr(x2,y2);
  d:=d*d;
  readln(n);
  for i:=1 to n do
    begin
      readln(x,y);
      if ((x*x+y*y)>d) then begin writeln('NO');continue;end;
      th:=dr(x,y);
      if (th1<=th2)
        then
          begin
            if (((th1-mm)<th) and ((th2+mm)>th)) then begin writeln('YES');continue;end
                                                else begin writeln('NO');continue;end
          end
        else
          begin
            if (((th1-mm)<th) or ((th2+mm)>th)) then begin writeln('YES');continue;end
                                               else begin writeln('NO');continue;end;
          end;
    end;
end.