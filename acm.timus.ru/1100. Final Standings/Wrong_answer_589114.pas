type
 team=record
       id:longint;
       pn:byte;
      end;
var
 i,n,j,id,m,r:longint;
begin
 for r:=0 to 100 do
 begin
 reset(input);
 read(n);
 for i:=1 to n do
  begin
   read(id,m);
   if m=r then writeln(id,' ',m);
  end;
 end;
end.
