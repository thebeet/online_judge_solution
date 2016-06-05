type
  p=record
      x,y:longint;
    end;

var
  ti,tn,i,n,m,l,x,y:longint;
  tm:array [0..301,0..301] of char;

procedure check(x,y:longint);
  var
    i,j:longint;
  begin
    tm[x,y]:='.';
    for i:=-1 to 1 do
      for j:=-1 to 1 do
        if ((x+i)>0) and ((x+i)<=n) and ((y+j)>0) and ((y+j)<=n) and (tm[x+i,y+j]='*')
          then
            begin
              tm[x,y]:='#';
              exit;
            end;
    for i:=-1 to 1 do
      for j:=-1 to 1 do
        if ((x+i)>0) and ((x+i)<=n) and ((y+j)>0) and ((y+j)<=n) and (tm[x+i,y+j]='?')
          then
              check(x+i,y+j);
  end;

begin
  readln(tn);
  for ti:=1 to tn do
    begin
      writeln('Scenario #',ti,':');
      fillchar(tm,sizeof(tm),'?');
      readln(n);
      readln(m);
      for i:=1 to m do
        begin
          readln(x,y);
          tm[x,y]:='*';
        end;
      check((n+1) div 2,(n+1) div 2);
      for x:=1 to n do
        begin
          for y:=1 to n do
            write(tm[x,y]);
          writeln;
        end;
      writeln;
    end;
end.
