type
 hpt=array [0..2200] of longint;
function hp_max_hp(var hp1,hp2:hpt):longint;
 var
  i:longint;
 begin
  if (hp1[0]>hp2[0]) then begin hp_max_hp:=1;exit;end;
  if (hp1[0]<hp2[0]) then begin hp_max_hp:=-1;exit;end;
  for i:=hp1[0] downto 1 do
   begin
    if (hp1[i]>hp2[i]) then begin hp_max_hp:=1;exit;end;
    if (hp1[i]<hp2[i]) then begin hp_max_hp:=-1;exit;end;
   end;
  hp_max_hp:=0;
 end;
var
 i,n,m:longint;
 hp,hp1,hp2:hpt;
 ch:char;
begin
 n:=0;
 while not eoln do
  begin
   read(ch);
   inc(n);
   hp[n]:=(ord(ch)-48) mod 10;
  end;
 hp1[0]:=n shr 1;
 hp2[0]:=n shr 1;
 m:=0;
 for i:=1 to (n shr 1) do
  begin
   hp1[i]:=hp[(n shr 1)-i+1];
   hp2[i]:=hp[n-(n shr 1)+i];
  end;
 if (hp_max_hp(hp1,hp2)>=0)
  then
   begin
    for i:=(n div 2) downto 1 do
     write(hp1[i]);
    for i:=1 to (n mod 2) do
     write(hp[(n shr 1)+1]);
    for i:=1 to (n div 2) do
     write(hp1[i]);
    writeln;
   end
  else
     if (((n mod 2)=1) and (hp[(n shr 1)+1]<>9))
      then
       begin
       inc(hp[(n shr 1)+1]);
    for i:=(n div 2) downto 1 do
     write(hp1[i]);
    for i:=1 to (n mod 2) do
     write(hp[(n shr 1)+1]);
    for i:=1 to (n div 2) do
     write(hp1[i]);
    writeln;
       end
       else
       begin
       hp1[1]:=hp1[1]+1;
       i:=1;
       while (hp1[i]=10) do
        begin
         hp1[i]:=0;
         inc(hp1[i+1]);
         inc(i);
        end;
       for i:=(n div 2) downto 1 do
       write(hp1[i]);
       for i:=1 to (n mod 2) do
       write('0');
       for i:=1 to (n div 2) do
       write(hp1[i]);
       writeln;
   end;


end.
