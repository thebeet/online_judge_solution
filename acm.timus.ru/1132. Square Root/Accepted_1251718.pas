var
  ti,tn,i,x,p,a1,a2:longint;

procedure swap(var a,b:longint);
  var
    t:longint;
  begin
    t:=a;
    a:=b;
    b:=t;
  end;

function mi_mod(x,n,p:longint):longint;
  var
    i,m,s:longint;
    bin2:array [0..20] of longint;
  begin
    fillchar(bin2,sizeof(bin2),0);
    m:=0;
    while (n>0) do
      begin
        inc(m);
        bin2[m]:=n mod 2;
        n:=n shr 1;
      end;
    s:=1;
    for i:=m downto 1 do
      if (bin2[i]>0)
        then
          s:=(((s*s) mod p)*x) mod p
        else
          s:=(s*s) mod p;
    mi_mod:=s;
  end;

function pp(a,p:longint):longint;
  var
    i,b,s,t,m,n,mp:longint;
    l:array [0..20] of longint;
  begin
    b:=0;
    for i:=2 to p do
      if (mi_mod(i,(p-1) shr 1,p)<>1) then begin b:=i;break;end;
    s:=0;
    t:=p-1;
    while ((t mod 2)=0) do
      begin
        inc(s);
        t:=t shr 1;
      end;
    m:=mi_mod(b,t,p);
