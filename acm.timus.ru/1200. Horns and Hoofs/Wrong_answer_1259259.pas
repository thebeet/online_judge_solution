var
  i:longint;
  n,m,ma,mb,mn,ta,tb,pa,pb,mx,l,ua,ub:int64;
  a,b:double;

function minn(n1,n2:int64):int64;
  begin
    if n1>n2 then exit(n2) else exit(n1);
  end;

begin
  readln(a,b);
  ta:=trunc(a*100+0.1);
  tb:=trunc(b*100+0.1);
  readln(mn);
  ma:=0;
  while ((ma+ma+1)*100<ta) do
    begin
      inc(ma);
      if (ma=mn) then break;
    end;
  mb:=0;
  while ((mb+mb+1)*100<tb) do
    begin
      inc(mb);
      if (mb=mn) then break;
    end;
  mx:=-1;
  ub:=-1;
  while (ub<=mb) do
    begin
      ub:=ub+1;
      ua:=minn(mn-ub,ma);
      l:=ua*ta+ub*tb-100*ua*ua-100*ub*ub;
      if (l>mx) then
        begin
          mx:=l;
          pa:=ua;
          pb:=ub;
        end;
    end;
  write(mx div 100,'.');
  mx:=mx mod 100;
  if (mx<10) then write('0');
  writeln(mx);
  writeln(pa,' ',pb);
end.
