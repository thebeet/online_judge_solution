var
  ti,tn,i,n,m,q,qn,s:longint;
  p:array [0..10000] of longint;
  l:array [0..10000] of longint;

procedure fj(n:longint);
  var
    i,q:longint;
  begin
    q:=trunc(sqrt(n));
    i:=2;
    while (i<=q) do
      begin
        if ((n mod i)=0)
          then
          begin
            inc(qn);
            p[qn]:=i;
            n:=n div i;
            l[qn]:=1;
            while ((n mod i)=0) do
              begin
                inc(l[qn]);
                n:=n div i;
              end;
            s:=s*(2*l[qn]+1);
            q:=trunc(sqrt(n));
          end;
        inc(i);
      end;
    if (n>1) then s:=s*3;
  end;

begin
  readln(tn);
  for ti:=1 to tn do
    begin
      writeln('Scenario #',ti,':');
      readln(n);
      s:=1;
      fj(n);
      s:=(s+1) div 2;
      writeln(s);
      writeln;
    end;
end.
