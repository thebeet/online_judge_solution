const
  mmm=0.00000001;

type
  citys=record
          x,y:double;
        end;

var
  i,j,h,n,m,l,r,r1,rr,s:longint;
  cs:array [0..101] of citys;
  c1,c2:citys;

function cross(var p1,p2,p3,p4:citys):boolean;
  var
    i,j:longint;
    mx,my,d1,d2:double;
  begin
    mx:=(p1.x+p2.x)/2;
    my:=(p1.y+p2.y)/2;
    d1:=(p1.x-mx)*(p1.x-mx)+(p1.y-my)*(p1.y-my);
    if (rr+mmm<d1) then exit(false);
    if (rr<=d1) then d2:=0 else d2:=sqrt(rr-d1);
    d1:=sqrt(d1);
    p3.x:=mx-d2/d1*(my-p1.y);
    p3.y:=my+d2/d1*(my-p1.y);
    p4.x:=mx+d2/d1*(my-p1.y);
    p4.y:=my-d2/d1*(my-p1.y);
    cross:=true;
  end;

begin
  readln(n);
  m:=0;
  for i:=1 to n do
    readln(cs[i].x,cs[i].y);
  readln(r,r1);
  r:=r-r1;
  if (r<0) then begin writeln('0');exit;end;
  rr:=r*r;
  m:=1;
  for i:=1 to n do
    for j:=(i+1) to n do
      begin
        if cross(cs[i],cs[j],c1,c2) then begin
        s:=0;
        for h:=1 to n do
          if ((cs[h].x-c1.x)*(cs[h].x-c1.x)+(cs[h].y-c1.y)*(cs[h].y-c1.y))<=(rr+mmm) then inc(s);
        if s>m then m:=s;
        s:=0;
        for h:=1 to n do
          if ((cs[h].x-c2.x)*(cs[h].x-c2.x)+(cs[h].y-c2.y)*(cs[h].y-c2.y))<=(rr+mmm) then inc(s);
        if s>m then m:=s;
        end;
      end;
  writeln(m);
end.
