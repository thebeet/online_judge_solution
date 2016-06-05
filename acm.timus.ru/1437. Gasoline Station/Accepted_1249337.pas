type
  oils=array [1..3] of longint;

var
  i,n,m:longint;
  l,sl:oils;
  hx:array [0..1000] of boolean;
  dp:array [0..256,0..256,0..256] of boolean;

procedure fill(var sl,tsl:oils;n:longint);
  var
    i:longint;
  begin
    for i:=1 to 3 do
      tsl[i]:=sl[i];
    tsl[n]:=l[n];
  end;

procedure tran(var sl,tsl:oils;f,t:longint);
  var
    i:longint;
  begin
    for i:=1 to 3 do
      tsl[i]:=sl[i];
    if (sl[f]+sl[t]<=l[t]) then begin tsl[t]:=sl[t]+sl[f];tsl[f]:=0;exit;end;
    tsl[f]:=sl[f]-(l[t]-sl[t]);
    tsl[t]:=l[t];
  end;

procedure add_stat(var sl:oils);
  begin
    hx[sl[1]]:=true;
    hx[sl[2]]:=true;
    hx[sl[3]]:=true;
    hx[sl[1]+sl[2]]:=true;
    hx[sl[2]+sl[3]]:=true;
    hx[sl[1]+sl[3]]:=true;
    hx[sl[1]+sl[2]+sl[3]]:=true;
  end;

procedure oil(sl:oils);
  var
    i:longint;
    tsl:oils;
  begin
    if (not dp[sl[1],sl[2],sl[3]]) then
      begin
        dp[sl[1],sl[2],sl[3]]:=true;
        for i:=1 to 3 do
          begin
            fill(sl,tsl,i);
            add_stat(tsl);
            oil(tsl);
            tran(sl,tsl,i,(i mod 3)+1);
            add_stat(tsl);
            oil(tsl);
            tran(sl,tsl,(i mod 3)+1,i);
            add_stat(tsl);
            oil(tsl);
          end;
      end;
  end;

begin
  read(l[1],l[2],l[3]);
  fillchar(hx,sizeof(hx),false);
  fillchar(dp,sizeof(dp),false);
  fillchar(sl,sizeof(sl),0);
  oil(sl);
  m:=0;
  for i:=1 to (l[1]+l[2]+l[3]) do
    if hx[i] then inc(m);
  writeln(m);
end.
