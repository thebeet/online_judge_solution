type
 team=record
       id:longint;
       pn:byte;
      end;
var
 i,n,j,id,m,r,d:longint;
begin
 d:=0;
 for r:=100 downto 0 do
 begin
 reset(input);
 read(n);
 if n=8 then n:=n div d;
 for i:=1 to n do
  begin
   read(id,m);
   if m=r then writeln(id,' ',m);
  end;
 end;
end.
