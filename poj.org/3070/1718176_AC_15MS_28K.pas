var
  ti,tn,i,n,m:longint;

function fib(var n,m:longint):longint;
  var
    i,nn,pn:longint;
    p1,p2,p3,t1,t2,t3:int64;
    bin:array [0..40] of longint;
  begin
    nn:=n;
    fillchar(bin,sizeof(bin),0);
    pn:=0;
    while (nn>0) do
      begin
        inc(pn);
        bin[pn]:=nn mod 2;
        nn:=nn div 2;
      end;
    p1:=0;p2:=1;p3:=1;
    if (n=0) then exit(0);
    if (n<3) then exit((1 mod m));
    for i:=(pn-1) downto 1 do
      begin
        t1:=(((p1*p1) mod m)+((p2*p2) mod m)) mod m;
        t3:=(((p3*p3) mod m)+((p2*p2) mod m)) mod m;
        t2:=(t3+m-t1) mod m;
        p1:=t1;p2:=t2;p3:=t3;
        if bin[i]=1 then
          begin
            p1:=p2;
            p2:=p3;
            p3:=((p3+p1) mod m);
          end;
      end;
    fib:=p2;
end;

begin
  readln(n);
  m:=10000;
  while (n>-1) do
    begin
      writeln(fib(n,m));
      readln(n);
    end;
end.

