const
  pi=3.1415926535897932384626433832795;
  mm=0.00000001;

var
  ti,tn,i,n,m,l,p,q:longint;
  a:array [0..20021] of double;
  ans:double;

function mn(n1,n2:double):double;
  begin
    if n1<n2 then exit(n1) else exit(n2);
  end;

procedure Sort(l, r: longint);
var
  i, j: longint;
  x,y:double;
begin
  i := l; j := r; x := a[(l+r) DIV 2];
  repeat
    while a[i] < x do i := i + 1;
    while x < a[j] do j := j - 1;
    if i <= j then
    begin
      y := a[i]; a[i] := a[j]; a[j] := y;
      i := i + 1; j := j - 1;
    end;
  until i > j;
  if l < j then Sort(l, j);
  if i < r then Sort(i, r);
end;

function find(s:double;f,t:longint):longint;
  var
    i,m:longint;
    p:double;
  begin
    if (f+1>=t) then
      begin
        m:=f;
        p:=abs(a[f]-(s+1));
        for i:=(f+1) to t do
          if (abs(a[i]-(s+1))<p)
            then
              begin
                m:=i;
                p:=abs(a[i]-(s+1));
              end;
        exit(m);
      end;
    m:=(f+t) div 2;
    if ((a[m]-s)>=1+mm) then
        exit(find(s,f,m));
    if ((a[m]-s)<=1-mm) then
        exit(find(s,m,t));
    exit(m);
  end;

begin
  readln(tn);
  for ti:=1 to tn do
    begin
      writeln('Scenario #',ti,':');
      readln(n);
      fillchar(a,sizeof(a),0);
      for i:=1 to n do
        begin
          readln(p,q);
          a[i]:=2*p/q;
        end;
      for i:=1 to n do
        a[i+n]:=a[i]+2;
      sort(1,n);
      ans:=1000;
      for i:=1 to n do
        ans:=mn(ans,abs((a[find(a[i],i,i+n)]-a[i])-1));
      ans:=(1-ans)*pi/2;
      ans:=sin(ans)*n*2;
      writeln(ans:0:2);
      writeln;
    end;
end.
