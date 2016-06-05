const
  tp=950231;

type
  node=record
         d:int64;
         h,p:longint;
       end;

var
  i,fre,ret,hh:longint;
  tt,a,b,n:int64;
  hxp:array [0..1000000] of longint;
  hx:array [0..1000000] of node;

function add(d:int64;h:longint):longint;
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
          hx[fre].h:=h;
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
    hx[fre].h:=h;
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
  hh:=1;
  ret:=add(tt,hh);
  while (ret=0) do
    begin
      inc(hh);
      tt:=(((tt*tt) mod n)*a+b) mod n;
      ret:=add(tt,hh);
    end;
  writeln(n-hh+ret);
  read(n);
  end;
end.
