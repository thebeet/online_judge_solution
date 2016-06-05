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
    i,b,s,t,tp,m,n,mp:longint;
    l:array [0..20] of longint;
  begin
    b:=0;
    for i:=2 to p do
      if (mi_mod(i,(p-1) shr 1,p)<>1) then begin b:=i;break;end;
    s:=0;
    tp:=p-1;
    while ((tp mod 2)=0) do
      begin
        inc(s);
        tp:=tp shr 1;
      end;
    t:=(p-1) shr s;
    m:=mi_mod(b,t,p);
    n:=mi_mod(x,t,p);
    fillchar(l,sizeof(l),0);
    mp:=0;
    for i:=1 to (s-1) do
      begin
        mp:=(mp shr 1)+l[i-1]*(1 shl (s-i+1));
        if (((mi_mod(m,mp,p)*mi_mod(n,1 shl (s-i-1),p)) mod p)=1)
          then
            l[i]:=0
          else
            l[i]:=1;
      end;
    mp:=(mp shr 1)+l[s-1];
    pp:=(mi_mod(m,mp,p)*mi_mod(a,(t+1) shr 1,p)) mod p;
  end;

begin
  readln(tn);
  for ti:=1 to tn do
    begin
      readln(x,p);
      x:=x mod p;
      if x=0 then begin writeln('0');continue;end;
      if (p=2) then begin writeln('1');continue;end;
      if (mi_mod(x,(p-1) shr 1,p)<>1)
        then
          writeln('No root')
        else begin
          if ((p mod 4)=3)
            then
              a1:=mi_mod(x,(p+1) shr 2,p)
            else
              if ((p mod 8)=5)
                then
                  if (mi_mod(x,(p-1) shr 2,p)=1)
                    then
                      a1:=mi_mod(x,(p+3) shr 3,p)
                    else
                      a1:=(mi_mod(2,(p-1) shr 2,p)*mi_mod(x,(p+3) shr 3,p)) mod p
                else
                  a1:=pp(x,p);
          a2:=(p*2-a1) mod p;
          if a1>a2 then swap(a1,a2);
          writeln(a1,' ',a2);
          end;
    end;
end.

