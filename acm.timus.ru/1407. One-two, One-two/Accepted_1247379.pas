type
  a=array [0..110] of longint;

var
  ans,an,a5:a;
  i,n,m,l:longint;

procedure hp_add_hp(var hp1,hp2:a);
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
    if t>0 then begin hp1[0]:=hp2[0]+1;hp1[hp1[0]]:=1;end else hp1[0]:=hp2[0];
  end;

procedure mu_5(var hp:a);
  var
    i,t:longint;
  begin
    t:=0;
    for i:=1 to hp[0] do
      begin
        hp[i]:=hp[i]*5+t;
        t:=hp[i] div 10;
        hp[i]:=hp[i] mod 10;
      end;
    if t>0 then begin inc(hp[0]);hp[hp[0]]:=t;end;
  end;

function div2(var ans:a):boolean;
  var
    i,n,m,t:longint;
  begin
    t:=0;
    for i:=ans[0] downto 1 do
      begin
        m:=(ans[i]+t*10) mod 2;
        ans[i]:=(ans[i]+t*10) div 2;
        t:=m;
      end;
    while ((ans[ans[0]]=0) and (ans[0]>0)) do dec(ans[0]);
  end;

begin
  readln(n);
  fillchar(a5,sizeof(a5),0);
  a5[1]:=1;
  a5[0]:=1;
  fillchar(an,sizeof(an),0);
  fillchar(ans,sizeof(ans),0);
  for i:=1 to n do
    begin
      if ((an[1] mod 2)=0)
        then
          begin
            ans[i]:=2;
            div2(an);
            hp_add_hp(an,a5);
          end
        else
          begin
            ans[i]:=1;
            hp_add_hp(an,a5);
            div2(an);
          end;
      mu_5(a5);
    end;
  for i:=n downto 1 do
    write(ans[i]);
  writeln;
end.
