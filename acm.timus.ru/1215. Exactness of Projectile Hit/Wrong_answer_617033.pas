var
 i,n,x,y,tx,ty,tx1,ty1,txt,tyt:longint;
 m,t:real;
function dis(x1,y1,x2,y2,px,py:longint):real;
 var
  a,b,c,s,k:real;
 begin
  if x1=x2
   then
    begin a:=1;b:=0;c:=-x1;end
   else
    begin
     a:=(y1-y2)/(x1-x2);
     c:=y1+a*x1;
     b:=1;
    end;
  dis:=abs((a*px+b*py+c))/sqrt(a*a+b*b);
 end;
begin
 m:=100000000;
 read(x,y,n);
 read(tx1,ty1);
 txt:=tx1;
 tyt:=ty1;
 for i:=2 to n do
  begin
   read(tx,ty);
   t:=dis(tx,ty,txt,tyt,x,y);
   if t<m then m:=t;
   txt:=tx;
   tyt:=ty;
  end;
 t:=dis(tx,ty,tx1,ty1,x,y);
 if t<m then m:=t;
 m:=m*2;
 writeln(m:0:3);
end.
