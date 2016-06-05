var
  i,j,n,m,l:longint;
  s,hx,nm:array [0..10000] of longint;

begin
  readln(n);
  fillchar(s,sizeof(s),0);
  fillchar(hx,sizeof(hx),0);
  fillchar(nm,sizeof(nm),0);
  for i:=1 to n do
    begin
      readln(nm[i]);
      s[i]:=(s[i-1]+nm[i]) mod n;
      if (s[i]=0)
        then
          begin
            writeln(i);
            for j:=1 to i do
              writeln(nm[j]);
            exit;
          end;
      if (hx[s[i]]>0)
        then
          begin
            writeln(i-hx[s[i]]);
            for j:=(hx[s[i]]+1) to i do
              writeln(nm[j]);
            exit;
          end
        else
          hx[s[i]]:=i;
    end;
end.