var
  ti,tn,i,n,pp,b,e,ans,fp:longint;
  p:array [0..101,0..101] of longint;
  dl:array [0..101] of longint;

begin
  readln(tn);
  for ti:=1 to tn do
    begin
      readln(n,pp);
      pp:=pp shr 1;
      fillchar(b,sizeof(b),0);
      fillchar(e,sizeof(e),0);
      fillchar(dl,sizeof(dl),0);
      for i:=1 to n do
        begin
          readln(b,e);
          inc(p[b,0]);
          inc(p[b,e]);
        end;
      ans:=0;
      for b:=1 to 100 do
        begin
          if (dl[b-1]>0) then
            begin
              ans:=1;
              break;
            end;
          for e:=b to 100 do
            dl[e]:=dl[e]+p[b,e];
          fp:=pp;
          for e:=b to 100 do
            if (dl[e]>0)
                  then
                    if (dl[e]>=fp)
                      then
                        begin
                          dl[e]:=dl[e]-fp;
                          fp:=0;
                          break;
                        end
                      else
                        begin
                          fp:=fp-dl[e];
                          dl[e]:=0;
                        end;

        end;
      if (ans=1)
        then
          begin
            writeln('serious trouble');
            continue;
          end;
      fillchar(dl,sizeof(dl),0);
      ans:=0;
      for b:=1 to 100 do
        begin
          if (dl[b-1]>0) then
            begin
              ans:=1;
              break;
            end;
          for e:=b to 100 do
            dl[e]:=dl[e]+p[b,e];
          fp:=pp;
          if ((b mod 7)=6) or ((b mod 7)=0) then fp:=0 else begin
          for e:=b to 100 do
            if (dl[e]>0)
                  then
                    if (dl[e]>=fp)
                      then
                        begin
                          dl[e]:=dl[e]-fp;
                          fp:=0;
                          break;
                        end
                      else
                        begin
                          fp:=fp-dl[e];
                          dl[e]:=0;
                        end;
            end;

        end;
      if (ans=1)
        then
          writeln('weekend work')
        else
          writeln('fine');
    end;
end.