var
 l:array [0..10000] of longint;
 i,n,m,a,b:longint;

begin
 read(n);
 l[0]:=0;
 for i:=1 to n do
  begin
   read(a);
   l[i]:=l[i-1]+a;
  end;
 read(m);
 for i:=1 to m do
  begin
   read(a,b);
   writeln(l[b]-l[a-1]);
  end;
end.

