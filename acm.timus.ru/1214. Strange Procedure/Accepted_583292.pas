var
 x,y:int64;
begin
 read(x,y);
 if ((((x+y) mod 2)=1) and (x>0) and (y>0)) then writeln(y,' ',x)
                    else writeln(x,' ',y);
end.
