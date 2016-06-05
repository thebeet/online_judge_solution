var
 i,n,m,n1,n2,n11,n22,j,t:longint;
 hp:array [0..1000000] of byte;
begin
 read(n);
 for i:=1 to (n div 2) do
  begin
   read(n1,n2);
   read(n11,n22);
   hp[i]:=n1*10+n11+n2*10+n22;
   j:=i;
   while (hp[j]>99) do
    begin
     hp[j]:=hp[j]-100;
     dec(j);
     inc(hp[j]);
    end;
  end;
 for i:=1 to (n mod 2) do
  begin
   read(n1,n2);
   hp[(n div 2)+1]:=(n1+n2) mod 10;
   j:=n div 2;
   hp[j]:=hp[j]+((n1+n2) div 10);
   while (hp[j]>99) do
    begin
     hp[j]:=hp[j]-100;
     dec(j);
     inc(hp[j]);
    end;
  end;
 for i:=1 to (n div 2) do
  begin
   if (hp[i]<10) then write('0');
   write(hp[i]);
  end;
 for i:=1 to (n mod 2) do
  writeln(hp[(n div 2)+1]);
end.