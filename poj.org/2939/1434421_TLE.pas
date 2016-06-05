const
  tp=11915417;

type
  node=record
         d:int64;
         h,p:longint;
       end;

var
  i,fre,ret,hh:longint;
  tt,a,b,n:int64;
  hxp:array [0..12000000] of longint;
  hx:array [0..1000001] of node;

function add(d:int64):longint;
  var
    i,n,p,pp:longint;
  begin
    p:=d mod tp;
    inc(fre);
    if (hxp[p]=0)
      then
        begin
          hxp[p]:=fre;
          hx[fre].d:=d;
          hx[fre].h:=fre;
          hx[fre].p:=0;
          exit(0);
        end;
    pp:=hxp[p];
    p:=hxp[p];
    while (hx[p].p>0) do
      begin
        if (hx[p].d=d) then exit(hx[p].h);
        pp:=p;
        p:=hx[p].p;
      end;
    if (hx[p].d=d) then exit(hx[p].h);
    hx[pp].p:=fre;
    hx[fre].d:=d;
    hx[fre].h:=fre;
    hx[fre].p:=0;
    exit(0);
  end;

begin
  read(n);
  while (n>0) do
  begin
  fre:=0;
  fillchar(hxp,sizeof(hxp),0);
  read(a,b);
  tt:=0;
  ret:=add(tt);
  while (ret=0) do
    begin
      tt:=(a*((tt*tt) mod n)+b) mod n;
      ret:=add(tt);
    end;
  writeln(n-fre+ret);
  read(n);
  end;
end.
