var
  i,a,b,st,p,l,n,s:longint;

begin
  readln(a,b);
  s:=1;
  st:=0;
  read(p);
  for i:=(a+1) to b do
    begin
      read(l);
      if ((st>0) and (l<p)) then begin st:=0;inc(s);p:=l;continue;end;
      if ((st<0) and (l>p)) then begin st:=0;inc(s);p:=l;continue;end;
      if ((st=0) and (l<p)) then begin st:=-1;p:=l;continue;end;
      if ((st=0) and (l>p)) then begin st:=1;p:=l;continue;end;
      p:=l;
    end;
  writeln(s);
end.
