var
  i,n,p,l:longint;
  f:boolean;

begin
  while not eof do
    begin
      read(n);
      read(p);
      f:=true;
      for i:=2 to n do
       begin
         read(l);
         if (abs(p-l)>=n) then begin writeln('Not jolly');f:=false;break;end;
         p:=l;
       end;
     if f then writeln('Jolly');
     readln;
   end;
end.

