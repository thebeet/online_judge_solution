const
 pi=3.14159265;
 s2=1.41421356;
var
 w,l,t,g:real;
 ans:real;
begin
 ans:=0;
 read(w,l);
 ans:=l*l*pi;
 if (((w/2)<l) and ((w/s2)>l))
  then
   begin
    t:=sqrt(l*l-w*w/4);
    ans:=ans+t*w*2;
    g:=arctan(t/(w/2));
    ans:=ans-g*4*l*l;
   end;
 if ((w/s2)<=l)
  then ans:=w*w;
 writeln(ans:0:3);
end.