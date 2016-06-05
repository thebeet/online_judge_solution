const
  sq3=1.7320508075688772935274463415059;

type
  p=record
      x,y:double;
    end;

var
  p1,p2,p3,p12,p21,p23,p32,pt,px:p;
  mm:double;

procedure a(var p1,p2,px1,px2:p);
  var
    tp:p;
  begin
    tp.x:=(p1.x+p2.x)/2;
    tp.y:=(p1.y+p2.y)/2;
    px1.x:=tp.x+(tp.y-p1.y)*sq3;
    px1.y:=tp.y-(tp.x-p1.x)*sq3;
    px2.x:=tp.x-(tp.y-p1.y)*sq3;
    px2.y:=tp.y+(tp.x-p1.x)*sq3;
  end;

function d(p1,p2:p):double;
  begin
    d:=sqrt(((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
  end;

procedure cross(var pa,pb,pc,pd,px:p);
  var
    d1,d2:double;
  begin
    d1:=abs((pd.x-pa.x)*(pb.y-pa.y)-(pb.x-pa.x)*(pd.y-pa.y));
    d2:=abs((pc.x-pa.x)*(pb.y-pa.y)-(pb.x-pa.x)*(pc.y-pa.y));
    px.x:=pd.x+(pc.x-pd.x)*d1/(d1+d2);
    px.y:=pd.y+(pc.y-pd.y)*d1/(d1+d2);
  end;

procedure m(pp:p);
  var
    t:double;
  begin
    t:=d(p1,pp)+d(p2,pp)+d(p3,pp);
    if (t<mm) then
      begin
        mm:=t;
        px:=pp;
      end;
  end;

begin
  readln(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
  mm:=100000000;
  m(p1);
  m(p2);
  m(p3);
  a(p1,p2,p12,p21);
  a(p2,p3,p23,p32);
  cross(p12,p3,p23,p1,pt);
  m(pt);
  cross(p21,p3,p23,p1,pt);
  m(pt);
  cross(p12,p3,p32,p1,pt);
  m(pt);
  cross(p21,p3,p32,p1,pt);
  m(pt);
  writeln(px.x:0:8,' ',px.y:0:8);
end.
