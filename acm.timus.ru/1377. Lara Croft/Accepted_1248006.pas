type
  map=array [0..101,0..101] of byte;

var
  i,j,n,m,l,x,y,dx,dy:longint;
  tm:map;

procedure turn;
  begin
    if ((dx=0) and (dy=1)) then begin dx:=1;dy:=0;exit;end;
    if ((dx=1) and (dy=0)) then begin dx:=0;dy:=-1;exit;end;
    if ((dx=0) and (dy=-1)) then begin dx:=-1;dy:=0;exit;end;
    if ((dx=-1) and (dy=0)) then begin dx:=0;dy:=1;exit;end;
  end;

begin
  readln(n,m);
  fillchar(tm,sizeof(tm),0);
  for i:=1 to n do
    for j:=1 to m do
      tm[i,j]:=1;
  readln(x,y);
  tm[x,y]:=2;
  readln(x,y);
  tm[x,y]:=2;
  x:=1;y:=0;dx:=0;dy:=1;
  while true do
    begin
      x:=x+dx;
      y:=y+dy;
      if (tm[x+dx,y+dy]=0) then turn;
      if tm[x,y]=2 then begin tm[x,y]:=0;break;end;
      tm[x,y]:=0;
    end;
  i:=0;
  while true do
    begin
      inc(i);
      x:=x+dx;
      y:=y+dy;
      if (tm[x+dx,y+dy]=0) then turn;
      if tm[x,y]=2 then begin tm[x,y]:=0;break;end;
      tm[x,y]:=0;
    end;
  writeln(i);
end.