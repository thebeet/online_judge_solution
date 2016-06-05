var
  i,j,k,h,n,m,t,nn,pt,ans:longint;
  ss:array [0..1000] of string;
  u:array [0..100] of boolean;
  s:string;
  f,flag:boolean;

begin
  readln(n);
  while (n>0) do
    begin
      ans:=0;
      for i:=1 to n do
        readln(ss[i]);
      readln(s);
      t:=0;
      i:=1;
      while (i<=length(s)) do
        if (s[i]='_') then
          begin
            inc(t);
            delete(s,i,1);
          end
        else
          inc(i);
      for i:=1 to n do
        begin
          fillchar(u,sizeof(u),true);
          pt:=t;
          f:=true;
          for j:=1 to length(ss[i]) do
            begin
              flag:=false;
              for k:=1 to length(s) do
                if ((ss[i][j]=s[k]) and (u[k])) then
                  begin
                    u[k]:=false;
                    flag:=true;
                    break;
                  end;
              if (flag=false) then dec(pt);
              if (pt<0)
                then
                  begin
                    f:=false;
                    break;
                  end;
            end;
          if f then inc(ans);
        end;
      writeln(ans);
      readln(n);
    end;
end.
