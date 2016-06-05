var
  ch:char;
  d:array [0..10] of longint;
  i,n,m,p:longint;
  x,y,q:double;

begin
  q:=sqrt(2)/2;
  fillchar(d,sizeof(d),0);
  read(ch);
  p:=ord(ch)-48;
  while ((p>0) and (p<10)) do
    begin
      inc(d[p]);
      read(ch);
      p:=ord(ch)-48;
    end;
  x:=d[6]-d[4]+(d[9]+d[3]-d[1]-d[7])*q;
  y:=d[8]-d[2]+(d[9]+d[7]-d[1]-d[3])*q;
  writeln(x:0:10,' ',y:0:10);
end.


