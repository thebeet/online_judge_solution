 const
  max=2000;
 type
  letb=set of 'A'..'Z';
  lets=set of 'a'..'z';
  tjz=array [0..max] of char;
  ans=record
       l,r:longint;
       le:longint;
      end;
  letter=record
          ch:char;
          p:longint;
         end;
  tjz1=array [0..max] of letter;
 var
  i,n,ln,rln:longint;
  f1,f2:text;
  jz:tjz;
  tamax,ta1:ans;
  set1:letb;
  set2:lets;
  jz1:tjz1;
  ch:char;
 procedure ss(var tans:ans;pos:longint);
  var
   i,r,l:longint;
   flag:boolean;
  begin
   if ((pos mod 2)=1)
    then
     begin
      pos:=pos div 2;
      r:=pos;l:=pos;
      flag:=true;
      while flag do
       begin
        if (l>0) then dec(l) else break;
        if (r<rln) then inc(r) else begin inc(r);break;end;
        if (jz1[r].ch<>jz1[l].ch) then flag:=false;
       end;
     end
    else
     begin
      pos:=pos div 2;
      r:=pos+1;l:=pos;
      flag:=true;
      if (jz1[r].ch<>jz1[l].ch) then flag:=false;
      while flag do
       begin
        if (l>0) then dec(l) else break;
        if (r<rln) then inc(r) else begin inc(r);break;end;
        if (jz1[r].ch<>jz1[l].ch) then flag:=false;
       end;
     end;
   tans.le:=r-l-1;
   tans.r:=r-1;
   tans.l:=l+1;
  end;
 begin
   ln:=0;
   rln:=0;
   while (not eof) do
    begin
     inc(ln);
     read(ch);
     jz[ln]:=ch;
        inc(rln);
        jz1[rln].ch:=ch;
        jz1[rln].p:=ln;
    end;
  tamax.le:=0;
  tamax.r:=0;
  tamax.l:=0;
  for i:=1 to (rln*2-1) do { S }
   begin
    ss(ta1,i);
    if (ta1.le>tamax.le) then tamax:=ta1;
   end;
   for i:=jz1[tamax.l].p to jz1[tamax.r].p do
    write(jz[i]);
   writeln;
 end.

