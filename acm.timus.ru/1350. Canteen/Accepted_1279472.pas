var
  i,j,n,m,k,l0,l:longint;
  food:array [0..101] of string;
  pz:array [0..101] of longint;
  poz:array [0..101] of boolean;
  f:string;

function find(var f:string):longint;
  var
    i:longint;
  begin
    for i:=1 to n do
      if (food[i]=f)
        then
          exit(i);
  end;

begin
  readln(n);
  fillchar(poz,sizeof(poz),true);
  for i:=1 to n do
    readln(food[i]);
  readln(k);
  readln(l0);
  for i:=1 to l0 do
    begin
      readln(f);
      poz[find(f)]:=false;
    end;
  for i:=1 to k do
    begin
      readln(l);
      pz[i]:=0;
      for j:=1 to l do
        begin
          readln(f);
          if poz[find(f)] then inc(pz[i]);
        end;
    end;
  readln(m);
  m:=n-m-l0;
  for i:=1 to k do
    if (pz[i]=0)
      then
        writeln('YES')
      else
        if (m<pz[i])
          then
            writeln('NO')
          else
            writeln('MAYBE');
end.
