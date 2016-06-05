type
  hp=array [0..10000] of longint;

var
  i,n,m,l:longint;
  hp1,hp2:hp;

procedure hp_inc_hp(var hp1,hp2:hp);
  var
    i,t:longint;
  begin
    t:=0;
    for i:=1 to hp2[0] do
      begin
        hp1[i]:=hp1[i]+hp2[i]+t;
        t:=hp1[i] div 10;
        hp1[i]:=hp1[i] mod 10;
      end;
    if (t>0) then
      begin
        i:=hp2[0]+1;
        inc(hp1[i]);
        while (hp1[i]>9) do
          begin
            hp1[i]:=hp1[i] mod 10;
            inc(i);
            inc(hp1[i]);
          end;
        if i>hp1[0] then hp1[0]:=i;
      end;
  end;

procedure hp_dec_hp(var hp1,hp2:hp);
  var
    i,t:longint;
  begin
    t:=0;
    for i:=1 to hp2[0] do
      begin
        hp1[i]:=hp1[i]-hp2[i]-t;
        if hp1[i]<0 then
          begin
            t:=1;
            hp1[i]:=hp1[i]+10;
          end;
      end;
    if (t>0) then
      begin
        i:=hp2[0]+1;
        dec(hp1[i]