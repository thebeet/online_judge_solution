var
  i:longint;
  a,n,m,l:int64;

procedure swap(var a,b:int64);
  var
    temp:longint;
  begin
    temp:=a;
    a:=b;
    b:=temp;
  end;

function gcd(a,b:int64):int64;
  var
    r:int64;
  begin
    if (a<0) then a:=-a;
    if (b<0) then b:=-b;
    if (b>a) then swap(a,b);
    while (b>0) do
      begin
        r:=a mod b;
        a:=b;
        b:=r;
      end;
    gcd:=a;
  end;

function Euler(n:longint):longint;
  var
    i,s:longint;
  begin
    s:=1;
    for i:=2 to trunc(sqrt(n)) do
      if ((n mod i)=0)
        then
          begin
            s:=s*(i-1);
            n:=n div i;
            while ((n mod i)=0) do
              begin
                s:=s*i;
                n:=n div i;
              end;
          end;
    if (n<>1) then s:=s*(n-1);
    Euler:=s;
  end;

function mi_mod(x,t,m:int64):int64;
  var
    i:longint;
    n,s:int64;
    bin2:array [0..50] of longint;
  begin
    fillchar(bin2,sizeof(bin2),0);
    n:=0;
    while (t>0) do
      begin
        inc(n);
        bin2[n]:=t mod 2;
        t:=t div 2;
      end;
    s:=1;
    for i:=n downto 1 do
      if bin2[i]=1
        then
          s:=(((s*s) mod m)*x) mod m
        else
          s:=(s*s) mod m;
    mi_mod:=s;
  end;

begin
  readln(a,n);
  if (gcd(a,n)<>1) then begin writeln('0');exit;end;
  m:=Euler(n);
  for i:=1 to trunc(sqrt(m)) do
    if ((m mod i)=0) and (mi_mod(a,i,n)=1) then begin writeln(i);exit;end;
  for i:=trunc(sqrt(m)) downto 1 do
    begin
      l:=m div i;
      if ((m mod l)=0) and (mi_mod(a,l,n)=1) then begin writeln(l);exit;end;
    end;
end.
