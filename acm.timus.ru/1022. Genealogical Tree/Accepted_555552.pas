var
 i,n,t,j:longint;
 family:array [0..100,0..100] of longint;
 ff:boolean;
begin
 ff:=true;
 fillchar(family,sizeof(family),0);
 read(n);
 for i:=1 to n do
  begin
   read(t);
   while (t<>0) do
    begin
     family[t,i
     ]:=1;
     inc(family[t,0]);
     read(t);
    end;
  end;
 for i:=1 to n do
  if (family[i,0]=0)
   then
    begin
     family[i,0]:=-1;
     if ff then ff:=false else write(' ');
     write(i);
     for j:=1 to n do
      if family[j,i]=1 then begin family[j,i]:=0;dec(family[j,0]);end;
     i:=0;
    end;
 writeln;
end.

