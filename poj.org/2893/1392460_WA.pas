var
  i,j,n,m,l,x,y,s,k:longint;
  tm,tmp:array [0..1001] of longint;

function merge(f,t:longint):longint;
  var
    i,sw,d,m1,m2,mm,s:longint;
  begin
    if ((f+1)=t)
      then
        if (tm[f]>tm[t])
          then
            begin
              sw:=tm[f];
              tm[f]:=tm[t];
              tm[t]:=sw;
              exit(1)
            end
          else
            exit(0);
    if (f=t)
      then
        exit(0);
    d:=(f+t) shr 1;
    s:=merge(f,d);
    s:=s+merge(d+1,t);
    for i:=f to t do
      tmp[i]:=tm[i];
    m1:=f;m2:=d+1;mm:=f-1;
    while ((m1<=d) and (m2<=t)) do
      begin
        inc(mm);
        if (tmp[m1]>tmp[m2])
          then
            begin
              tm[mm]:=tmp[m2];
              inc(m2);
              s:=(s+(d-m1)+1){ mod 2};
            end
          else
            begin
              tm[mm]:=tmp[m1];
              inc(m1);
            end;
      end;
    if (m1>d) then
      for i:=m2 to t do
        tm[i]:=tmp[i];
    if (m2>t) then
      for i:=m1 to d do
        tm[mm+i-m1+1]:=tmp[i];
    merge:=s{ mod 2};
  end;

begin
  readln(n,m);
  while ((n>0) and (m>0)) do
    begin
      s:=0;
      l:=0;
      for i:=1 to n do
        for j:=1 to m do
          begin
            inc(l);
            read(tm[l]);
            if tm[l]=0 then tm[l]:=n*m else begin
            x:=((tm[l]-1) div m)+1;
            y:=((tm[l]-1) mod m)+1;
            s:=(s+(i-x)+(j-y)+10000) mod 2;
            end;
          end;
      writeln(merge(1,n*m));
      if (((s+merge(1,n*m)) mod 2)=0) then writeln('YES') else writeln('NO');
      readln(n,m);
    end;
end.

