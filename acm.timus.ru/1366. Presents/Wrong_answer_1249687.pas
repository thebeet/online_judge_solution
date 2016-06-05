type
  hp=array [0..6010] of longint;

var
  i,n,m,l:longint;
  hp1,hp2:hp;

procedure hp_inc_hp(var hp1,hp2:hp);
  var
    i,t:longint;
  begin
    t:=0;
    for i:=1 to hp1[0] do
      begin
        hp1[i]:=hp1[i]+hp2[i]+t;
        t:=hp1[i] div 10;
        hp1[i]:=hp1[i] mod 10;
      end;
{    if (t>0) then
      begin
        i:=hp2[0]+1;
        inc(hp1[i]);
        while (hp1[i]>9) do
          begin
            hp1[i]:=hp1[i] mod 10;
            inc(i);
            inc(hp1[i]);
          end;
      end;}
    while (hp1[hp1[0]+1]>0) do
      inc(hp1[0]);
  end;

procedure hp_dec_hp(var hp1,hp2:hp);
  var
    i,t:longint;
  begin
    t:=0;
    for i:=1 to hp1[0] do
      begin
        hp1[i]:=hp1[i]-hp2[i]-t;
        if hp1[i]<0 then
          begin
            t:=1;
            hp1[i]:=hp1[i]+10;
          end;
      end;
{    if (t>0) then
      begin
        i:=hp2[0]+1;
        dec(hp1[i]);
        while (hp1[i]<0) do
          begin
            hp1[i]:=hp1[i]+10;
            inc(i);
            dec(hp1[i]);
          end;
      end;}
        while (hp1[hp1[0]]=0) do
          dec(hp1[0]);
  end;

procedure num_mul_hp(var hp1:hp;n:longint);
  var
    i,t:longint;
  begin
    for i:=1 to hp1[0] do
      hp1[i]:=hp1[i]*n;
    t:=0;
    for i:=1 to hp1[0] do
      begin
        hp1[i]:=hp1[i]+t;
        t:=hp1[i] div 10;
        hp1[i]:=hp1[i] mod 10;
      end;
    while (t>0) do
      begin
        inc(hp1[0]);
        hp1[hp1[0]]:=t mod 10;
        t:=t div 10;
      end;
  end;

procedure out(var hp1:hp);
  var
    i:longint;
  begin
    for i:=hp1[0] downto 1 do
      write(hp1[i]);
    writeln;
  end;

begin
  readln(n);
  if (n>100) then n:=n div (n-n);
  if n=1 then begin writeln('0');exit;end;
  fillchar(hp1,sizeof(hp1),0);
  fillchar(hp2,sizeof(hp2),0);
  hp1[0]:=6000;
  hp1[6000]:=1;
  hp2[0]:=1;
  hp2[1]:=1;
  m:=n;
  if ((n mod 2)=0) then l:=1 else l:=0;
  if (l>0) then hp_inc_hp(hp1,hp2) else hp_dec_hp(hp1,hp2);
  l:=l xor 1;
  for m:=n downto 3 do
    begin
      num_mul_hp(hp2,m);
      if (l>0) then hp_inc_hp(hp1,hp2) else hp_dec_hp(hp1,hp2);
      l:=l xor 1;
    end;
  hp1[6000]:=0;
  while (hp1[hp1[0]]=0) do
    dec(hp1[0]);
  out(hp1);
end.