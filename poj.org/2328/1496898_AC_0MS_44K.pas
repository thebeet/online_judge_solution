var
  i,n,k,l:longint;
  num:array [0..11] of boolean;
  st:string;

begin
  readln(n);
  while (n>0) do
    begin
      fillchar(num,sizeof(num),true);
      readln(st);
      while (st[5]<>'t') do
        begin
          if (st[5]='l') then for i:=1 to n do num[i]:=false;
          if (st[5]='h') then for i:=n to 10 do num[i]:=false;
          readln(n);
          readln(st);
        end;
      if num[n] then writeln('Stan may be honest')
                else writeln('Stan is dishonest');
      readln(n);
    end;
end.