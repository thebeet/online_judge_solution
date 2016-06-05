const
  pi=3.14159265358979;
  h=1000;

var
  ix,iy,i,n,k:longint;
  x,y,r:double;
  tm:array [0..h,0..h] of boolean;

begin
  readln(n);
  fillchar(tm,sizeof(tm),false);
  for i:=1 to n do
    begin
      readln(x,y,r);
      x:=x*h;
      y:=y*h;
      r:=r*r*h*h;
      for ix:=0 to h do
        for iy:=0 to h do
          if (((ix-x)*(ix-x)+(iy-y)*(iy-y))<r) then tm[ix,iy]:=true;
    end;
  k:=0;
  for ix:=1 to 1000 do
    for iy:=1 to 1000 do
      if tm[ix,iy] then inc(k);
  r:=100*k/h/h;
  writeln(r:0:6);
end.