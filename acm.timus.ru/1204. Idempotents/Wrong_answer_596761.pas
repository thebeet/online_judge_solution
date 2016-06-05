var
 i,j,m,p1,p2:longint;
 yy,n:int64;
 flag:boolean;
 f1,f2:text;
procedure fj(var n:int64;var p1,p2:longint);
 var
  i,t,s:longint;
 begin
  if ((n mod 2)=0) then begin p1:=2;p2:=n div 2;exit;end;
  t:=1;
  s:=(trunc(sqrt(n)) div 2)+1;
  for i:=2 to s do
   begin
    t:=t+2;
    if ((n mod t)=0) then begin p1:=t;p2:=n div t;exit;end;
   end;
 end;
begin
 assign(f1,'2.in');
 assign(f2,'2.out');
 reset(f1);
 rewrite(f2);
 read(f1,m);
 for i:=1 to m do
  begin
   read(f1,n);
   flag:=true;
   write(f2,'0 1');
   fj(n,p1,p2);
   yy:=p2;
   while flag do
    begin
     if (((yy*yy) mod n)=yy)
      then
       begin
        if (yy>n+1-yy) then write(f2,' ',n+1-yy,' ',yy);
        if (yy<n+1-yy) then write(f2,' ',yy,' ',n+1-yy);
        if (yy=n+1-yy) then write(f2,' ',yy);
        flag:=false;
       end;
     yy:=yy+p2;
    end;
   writeln(f2);
  end;
 close(f2);
end.
