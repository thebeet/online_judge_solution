var
  i,n,p,l:longint;
  f:array [0..3000] of boolean;
  fl:boolean;
begin
  while not eof do
    begin
      read(n);
      read(p);
      fl:=true;
      fillchar(f,sizeof(f),true);
      for i:=2 to n do
       begin
         read(l);
         if ((abs(p-l)>=n) or (not f[abs(p-l)])) then begin writeln('Not jolly');fl:=false;break;end;
         f[abs(p-l)]:=false;
         p:=l;
       end;
     if fl then writeln('Jolly');
     readln;
   end;
end.

