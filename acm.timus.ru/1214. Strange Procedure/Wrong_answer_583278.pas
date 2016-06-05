var
 x,y:longint;
begin
 read(x,y);
 if (((x mod 2)+(y mod 2)) mod 2)=1 then writeln(y,' ',x)
                                    else writeln(x,' ',y);
end.
