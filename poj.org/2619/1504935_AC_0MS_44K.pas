var
 i,n,m,a,b,xa,xb,ya,yb,t,s,x1,xm:longint;
begin
 read(a,b);
 if a>b then begin t:=a;a:=b;b:=t;end;
 ya:=trunc(sqrt(a-1))+1;
 xa:=a-(ya-1)*(ya-1);
 yb:=trunc(sqrt(b-1))+1;
 xb:=b-(yb-1)*(yb-1);
 if (ya=yb) then begin writeln(xb-xa);exit;end;
 s:=(yb-ya)*2+1;
 if ((xa mod 2)=1) then dec(s);
 x1:=xa;
 xm:=2*yb-1-((2*ya-1)-xa);
 if ((xa mod 2)=0) then begin dec(x1);inc(xm);end;
 if (xb>xm) then begin writeln(s+xb-xm);exit;end;
 if (xb<x1) then begin writeln(s-xb+x1);exit;end;
 if ((xb mod 2)=0) then dec(s);
 writeln(s);
end.
