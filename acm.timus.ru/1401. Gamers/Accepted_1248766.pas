type
  map=array [0..600,0..600] of longint;

var
  i,n,m,x,y,id:longint;
  tm:map;

procedure make(x,y,w,sx,sy:longint);
  var
    i,j,tx,ty,tw:longint;
  begin
    if w=2 then
      begin
        inc(id);
        if ((x<>sx) or (y<>sy)) then tm[x,y]:=id;
        if ((x+1<>sx) or (y<>sy)) then tm[x+1,y]:=id;
        if ((x<>sx) or (y+1<>sy)) then tm[x,y+1]:=id;
        if ((x+1<>sx) or (y+1<>sy)) then tm[x+1,y+1]:=id;
        exit;
      end;
    tw:=w div 2;
    tx:=x+tw;
    ty:=y+tw;
    if ((sx>=tx) and (sy>=ty))
      then
        begin
          inc(id);
          tm[tx-1,ty-1]:=id;
          tm[tx,ty-1]:=id;
          tm[tx-1,ty]:=id;
          make(x,y,tw,tx-1,ty-1);
          make(tx,y,tw,tx,ty-1);
          make(x,ty,tw,tx-1,ty);
          make(tx,ty,tw,sx,sy);
        end;
    if ((sx<tx) and (sy>=ty))
      then
        begin
          inc(id);
          tm[tx-1,ty-1]:=id;
          tm[tx,ty-1]:=id;
          tm[tx,ty]:=id;
          make(x,y,tw,tx-1,ty-1);
          make(tx,ty,tw,tx,ty);
          make(tx,y,tw,tx,ty-1);
          make(x,ty,tw,sx,sy);
        end;
    if ((sx>=tx) and (sy<ty))
      then
        begin
          inc(id);
          tm[tx-1,ty-1]:=id;
          tm[tx,ty]:=id;
          tm[tx-1,ty]:=id;
          make(x,y,tw,tx-1,ty-1);
          make(tx,ty,tw,tx,ty);
          make(x,ty,tw,tx-1,ty);
          make(tx,y,tw,sx,sy);
        end;
    if ((sx<tx) and (sy<ty))
      then
        begin
          inc(id);
          tm[tx,ty]:=id;
          tm[tx,ty-1]:=id;
          tm[tx-1,ty]:=id;
          make(tx,ty,tw,tx,ty);
          make(tx,y,tw,tx,ty-1);
          make(x,ty,tw,tx-1,ty);
          make(x,y,tw,sx,sy);
        end;
  end;

procedure out;
  var
    i,j:longint;
  begin
    for i:=1 to m do
      begin
        for j:=1 to (m-1) do
          write(tm[i,j],' ');
        writeln(tm[i,m]);
      end;
  end;

begin
  readln(n);
  m:=1 shl n;
  readln(x,y);
  fillchar(tm,sizeof(tm),0);
  id:=0;
  make(1,1,m,x,y);
  out;
end.
