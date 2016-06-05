var
 i,n,t,s,z,j:longint;
 abcd:array [0..9] of boolean;
 ch:char;
begin
 readln(n);
 for i:=1 to n do
  begin
   z:=0;
   fillchar(abcd,sizeof(abcd),false);
   s:=0;
   read(ch);
   while (ord(ch)>40) do
    begin
     t:=ord(ch);
     t:=(t-8) mod 10;
     if ((t<5) and (t>0) and (abcd[t]=false))
      then
       abcd[t]:=true
      else
       if t=0 then inc(z) else
       begin
        s:=(s*10+t) mod 7;
        write(t);
       end;
     read(ch);
    end;
   s:=(s*10000) mod 7;
   case s of
    0:write('4123');
    1:write('2134');
    2:write('1342');
    3:write('1243');
    4:write('2341');
    5:write('1234');
    6:write('1324');
   end;
   for j:=1 to z do
    begin
     s:=(s*10) mod 7;
     write('0');
    end;
   writeln;
   readln;
  end;
end.