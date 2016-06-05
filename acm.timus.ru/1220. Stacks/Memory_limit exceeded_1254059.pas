var
  i,n:longint;
  ch1,ch2:char;
  p:array [0..100000] of longint;
  d:array [0..100000] of word;
  pp:array [0..1000] of longint;

begin
  fillchar(p,sizeof(p),0);
  fillchar(d,sizeof(d),0);
  fillchar(pp,sizeof(pp),0);
  readln(n);
  for i:=1 to n do
    begin
      read(ch1,ch2);
      if (ch2='U') then
        begin
          read(ch1);
          read(ch1);
          read(ch1);
          readln(d[i],p[i]);
          pp[d[i]]:=i;
        end;
      if (ch2='O') then
        begin
          read(ch1);
          read(ch1);
          readln(d[i]);
          while true do
            begin
              while (d[pp[d[i]]]<>d[i]) do
                dec(pp[d[i]]);
              if (p[pp[d[i]]]>0) then break
                                 else pp[d[i]]:=-p[pp[d[i]]];
            end;
          writeln(p[pp[d[i]]]);
          dec(pp[d[i]]);
          p[i]:=-pp[d[i]];
        end;
    end;
end.
