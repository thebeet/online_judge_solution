var
  p1,p2,p3,i:longint;
  ch1,ch2:char;
  p:array [0..10001] of longint;

begin
  p[1]:=32;
  i:=1;
  while not eoln do
    begin
      inc(i);
      read(ch1,ch2);
      if (ord(ch1)<60) then p[i]:=16*(ord(ch1)-48) else p[i]:=16*(ord(ch1)-55);
      if (ord(ch2)<60) then p[i]:=p[i]+ord(ch2)-48 else p[i]:=p[i]+ord(ch2)-55;
    end;
  readln;
  i:=0;
  p2:=0;
  while not eoln do
    begin
      inc(i);
      read(ch1,ch2);
      if (ord(ch1)<60) then p1:=16*(ord(ch1)-48) else p1:=16*(ord(ch1)-55);
      if (ord(ch2)<60) then p1:=p1+ord(ch2)-48 else p1:=p1+ord(ch2)-55;
      p2:=p1 xor p2 xor p[i];
      if ((p2 shr 4)>9) then write(chr((p2 shr 4)+55)) else write(chr((p2 shr 4)+48));
      if ((p2 mod 16)>9) then write(chr((p2 mod 16)+55)) else write(chr((p2 mod 16)+48));
    end;
  writeln;
end.