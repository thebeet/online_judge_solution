type
  s=record
      d:word;
      p:longint;
    end;

var
  i,n,p,d:longint;
  ch1,ch2:char;
  ss:array [0..100000] of s;
  pp:array [0..1000] of longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(ch1,ch2);
      if (ch2='U') then
        begin
          read(ch1);
          read(ch1);
          read(ch1);
          readln(ss[i].d,ss[i].p);
          pp[ss[i].d]:=i;
        end;
      if (ch2='O') then
        begin
          read(ch1);
          read(ch1);
          readln(ss[i].d);
          ss[i].p:=-1;
        end;
    end;
  for i:=n downto 1 do
    if (ss[i].p<0)
      then
        begin
          while ((ss[pp[ss[i].d]].d<>ss[i].d) or (ss[pp[ss[i].d]].p<0)) do
            dec(pp[ss[i].d]);
          writeln(ss[pp[ss[i].d]].p);
          dec(pp[ss[i].d]);
        end;
end.