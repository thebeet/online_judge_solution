var
  i,n,m:longint;

begin
  readln(n);
  if ((n mod 2)=0)
    then
      begin
        n:=n div 2;
        write('1');
        for i:=3 to n do
          write('1');
        if n>1 then write('0');
        for i:=3 to n do
          write('8');
        if n>1 then write('9');
        write('0');
        writeln;
      end
    else
      begin
       n:=n div 2;
        write('1');
        for i:=3 to n do
          write('1');
        if n>1 then write('0');
        for i:=3 to n do
          write('8');
        if n>1 then write('9');
        write('00');
        writeln;
      end;
end.
