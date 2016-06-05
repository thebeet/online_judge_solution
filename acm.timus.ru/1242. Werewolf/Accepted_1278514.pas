var
  i,j,n,m,c,p:longint;
  flag:boolean;
  st:string;
  pp:array [0..1001,0..2] of longint;
  gp:array [0..1001] of boolean;
  cc:array [0..1001,0..1001] of longint;
  cp:array [0..1001] of boolean;

procedure gop(p:longint);
  var
    i:longint;
  begin
    if gp[p] then exit;
    gp[p]:=true;
    for i:=1 to pp[p][0] do
      gop(pp[p][i]);
  end;

procedure cop(p:longint);
  var
    i:longint;
  begin
    if cp[p] then exit;
    cp[p]:=true;
    for i:=1 to cc[p][0] do
      cop(cc[p][i]);
  end;

begin
  fillchar(cc,sizeof(cc),0);
  fillchar(pp,sizeof(pp),0);
  fillchar(gp,sizeof(gp),false);
  fillchar(cp,sizeof(cp),false);
  readln(n);
  while (true) do
    begin
      readln(st);
      if (st='BLOOD') then break;
      m:=1;
      c:=0;
      while (ord(st[m])>40) do
        begin
          c:=c*10+ord(st[m])-48;
          inc(m);
        end;
      p:=0;
      for j:=m to length(st) do
        if (ord(st[j])>40)
          then
            p:=p*10+ord(st[j])-48;
      inc(pp[c][0]);
      pp[c][pp[c][0]]:=p;
      inc(cc[p][0]);
      cc[p][cc[p][0]]:=c;
    end;
  while not eof do
    begin
      readln(m);
      gop(m);
      cop(m);
    end;
  flag:=false;
  for i:=1 to n do
    if (not (gp[i] or cp[i]))
      then
        begin
          write(i,' ');
          flag:=true;
        end;
  if flag then writeln
          else writeln('0');
end.




