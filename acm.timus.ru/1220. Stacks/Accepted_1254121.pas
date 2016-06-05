var
  i,n,dd,pp,fp:longint;
  ch1,ch2:char;
  p:array [1..9000,0..15] of longint;
  d:array [1..1000] of longint;

procedure push(td,tp:longint);
  var
    i,dr,pr,t:longint;
  begin
    if (d[td]=0)
      then
        begin
          d[td]:=fp;
          fp:=p[fp,0];
          p[d[td],1]:=tp;
          p[d[td],0]:=1;
          exit;
        end;
    if ((p[d[td],0] mod 100)=15)
      then
        begin
          t:=d[td];
          d[td]:=fp;
          fp:=p[fp,0];
          p[d[td],0]:=100*t+1;
          p[d[td],1]:=tp;
          exit;
        end;
    inc(p[d[td],0]);
    p[d[td],(p[d[td],0] mod 100)]:=tp;
  end;

procedure pop(td:longint);
  var
    t:longint;
  begin
    writeln(p[d[td],(p[d[td],0] mod 100)]);
    dec(p[d[td],0]);
    if ((p[d[td],0] mod 100)=0)
      then
        begin
          t:=fp;
          fp:=d[td];
          d[td]:=p[d[td],0] div 100;
          p[fp,0]:=t;
        end;
  end;

begin
  fillchar(p,sizeof(p),0);
  for i:=0 to 7249 do
    p[i,0]:=i+1;
  fillchar(d,sizeof(d),0);
  fp:=1;
  readln(n);
  for i:=1 to n do
    begin
      read(ch1,ch2);
      if (ch2='U') then
        begin
          read(ch1);
          read(ch1);
          read(ch1);
          readln(dd,pp);
          push(dd,pp);
        end;
      if (ch2='O') then
        begin
          read(ch1);
          read(ch1);
          readln(dd);
          pop(dd);
        end;
    end;
end.
