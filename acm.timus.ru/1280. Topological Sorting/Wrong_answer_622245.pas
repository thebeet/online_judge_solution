var
 i,n,m,t,f,d:longint;
 trr:array [-1..1010,-1..127] of byte;
 nn:array [0..1001] of longint;
 able:array [0..1001] of boolean;
 tt:boolean;
procedure addsub(f,t:longint);
 var
  i,t2,t1:longint;
 begin
  inc(nn[t]);
  t2:=(t div 8)+1;
  t1:=1;
  for i:=1 to (t mod 8) do
   t1:=t1*2;
  trr[f,t2]:=trr[f,t2]+t1;
 end;
procedure readsub(f:longint);
 var
  i,t1,t2:longint;
 begin
  for i:=0 to 126 do
   begin
    t1:=trr[f,i];
    t2:=(i-1)*8-1;
    while (t1<>0) do
     begin
      inc(t2);
      if ((t1 mod 2)=1)
       then
        begin
         dec(nn[t2]);
         if nn[t2]=0 then able[t2]:=true;
        end;
      t1:=t1 shr 1;
     end;
   end;
 end;
begin
 fillchar(able,sizeof(able),false);
 fillchar(trr,sizeof(trr),0);
 d:=0;
 read(n,m);
 if n>1000 then n:=n div d;
 for i:=1 to m do
  begin
   read(f,t);
   addsub(f,t);
  end;
 tt:=true;
 for i:=1 to n do
  if (nn[i]=0)
   then
    begin
     able[i]:=true;
     tt:=false;
    end;
 if tt then begin writeln('NO');exit;end;
 for i:=1 to n do
  begin
   read(t);
   if (not able[t])
    then
     begin
      writeln('NO');
      exit;
     end;
   readsub(t);
  end;
 writeln('YES');
end.

