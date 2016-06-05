var
 i,n,m,a,b,t,ax,bx,ay,by,xm,s:longint;
procedure cc(var n,x,y:longint);
 begin
  y:=trunc(sqrt(n-1))+1;
  x:=n-(y-1)*(y-1);
 end;
begin
 read(a,b);
 if (a>b) then begin t:=a;a:=b;b:=t;end;
 cc(a,ax,ay);
 cc(b,bx,by);
 if (ay=by) then begin writeln(bx-ax);exit;end;
 xm:=2*by-1-(2*ay-1-ax);
 s:=(by-ay)*2+1;
 if ((ax mod 2)=1) then dec(s);
 if ((ay mod 2)=0) then dec(s);
 if (bx<ax) then begin if ((ax mod 2)=0) then dec(s);writeln(s+ax-bx);exit;end;
 if (bx>xm) then begin if ((ax mod 2)=0) then dec(s);writeln(s+bx-xm);exit;end;
 writeln(s);
end.