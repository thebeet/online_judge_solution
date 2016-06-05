type
 nm=array [0..230] of longint;

var
 i,j:longint;
 tn,tnt,ans,anst,hans:nm;

procedure read_tn(var tn:nm);var i:longint;t:string;begin readln(t);tn[0]:=length(t);for i:=1 to tn[0] do tn[i]:=ord(t[i])-48;end;

procedure hp_p(var tn:nm);
 var
  i:longint;
 begin
  for i:=1 to 230 do
   begin
    if (tn[i]>9) then
     begin tn[i+1]:=tn[i+1]+tn[i] div 10;tn[i]:=tn[i] mod 10;end;
    if (tn[i]<0) then
     begin tn[i]:=tn[i]+10;tn[i+1]:=tn[i+1]-1;dec(i);end;
   end;
  for i:=230 downto 1 do
   if tn[i]<>0 then begin tn[0]:=i;break;end;
 end;

procedure hp_add_hp(var n1,n2:nm);
 var
  i,l:longint;
 begin
  l:=n1[0];
  if (l<n2[0]) then l:=n2[0];
  for i:=1 to l do
   n1[i]:=n1[i]+n2[i];
  hp_p(n1);
 end;

procedure hp_c(var tn:nm;num:longint);
 var
  i:longint;
 begin
  for i:=1 to tn[0] do
   tn[i]:=tn[i]*num;
  hp_p(tn);
 end;

procedure inc_h(var tn:nm);
 var
  i:longint;
 begin
  i:=1;
  inc(tn[i]);
  while (tn[i]>9) do
   begin
    tn[i]:=0;
    inc(i);
    inc(tn[i]);
   end;
  hp_p(tn);
 end;

function goit(var tnt:nm;p:longint):boolean;
 var
  i,k:longint;
  f:boolean;
 begin
  while true do begin
  k:=tnt[0]+1;
  f:=true;
  for i:=(p+1) to tn[0] do
   begin
    dec(k);
    if k<1 then break;
    if tnt[k]<>tn[i] then begin f:=false;break;end;
   end;
  if f
   then
    begin
     if ((p+tnt[0])>=tn[0]) then exit(true);
     p:=p+tnt[0];
     inc_h(tnt);
     hp_p(tnt);
    end
   else
    exit(false);
  end;
 end;

procedure cc(var anst:nm);
 var
  i:longint;
 begin
  if anst[0]>hans[0] then exit;
  if anst[0]<hans[0] then begin hans:=anst;exit;end;
  for i:=anst[0] downto 1 do
   begin
    if anst[i]>hans[i] then exit;
    if anst[i]<hans[i] then begin hans:=anst;exit;end;
   end;
 end;

procedure add(var ans:nm;p:longint);
 var
  i,j,l:longint;
 begin
  l:=ans[0];
  fillchar(anst,sizeof(anst),0);
  if (ans[0]=2) then begin anst[0]:=1;anst[1]:=9;end;
  if (ans[0]>2)
   then
    begin
     anst[1]:=9;
     for i:=2 to (ans[0]-1) do
      anst[i]:=8;
     anst[ans[0]]:=ans[0]-2;
     hp_p(anst);
    end;
  dec(ans[ans[0]]);
  hp_p(ans);
  hp_c(ans,l);
  hp_add_hp(anst,ans);
  anst[1]:=anst[1]-p+1;
  hp_p(anst);
  if hans[0]=0 then hans:=anst
              