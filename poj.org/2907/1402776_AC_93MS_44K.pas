type
  p=record
      x,y:longint;
    end;
  d=array [0..12] of longint;

var
  tn,ti,i,n,m,l,mm,x,y:longint;
  p1,p2:p;
  b:array [0..12] of p;
  a:d;

procedure g(a:d;nn:longint);
  var
    i,s,j:longint;
    flag:boolean;
  begin
    if (nn=n)
      then
        begin
          s:=0;
          for i:=1 to (n+1) do
            s:=s+abs(b[a[i]].x-b[a[i-1]].x)+abs(b[a[i]].y-b[a[i-1]].y);
          if s<mm then mm:=s;
          exit;
        end;
    for i:=1 to n do
      begin
        flag:=true;
        for j:=1 to nn do
          if a[j]=i then
            begin
              flag:=false;
              break;
            end;
        if flag then
          begin
            a[nn+1]:=i;
            g(a,nn+1);
          end;
      end;
  end;

begin
  readln(tn);
  for ti:=1 to tn do
    begin
      mm:=10000000;
      fillchar(b,sizeof(b),0);
      fillchar(a,sizeof(a),0);
      readln(x,y);
      readln(b[0].x,b[0].y);
      readln(n);
      b[n+1]:=b[0];
      for i:=1 to n do
        readln(b[i].x,b[i].y);
      a[0]:=0;
      a[n+1]:=n+1;
      g(a,0);
      writeln('The shortest path has length ',mm);
    end;
end.