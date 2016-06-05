 var
   i,n,m,l:longint;
   chs:array [0..101] of char;
   bs,bs2:array [0..101] of longint;
 begin
  n:=0;
   while not eoln do
     begin
      inc(n);
       read(chs[n]);
      bs[n]:=ord(chs[n])-97;
    end;
  bs2[1]:=((bs[1]+26-5) mod 26);
  for i:=2 to n do
    bs2[i]:=((bs[i]+26-bs[i-1]) mod 26);
  for i:=1 to n do
    write(chr(bs2[i]+97));
end.
