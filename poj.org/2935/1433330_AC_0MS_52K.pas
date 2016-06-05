var
  i,j,k,l,dl1,dl2,p,px,ansn:longint;
  x1,x2,y1,y2,xw1,yw1,xw2,yw2,xt,yt:longint;
  go:array [0..7,0..7,0..7,0..7] of boolean;
  tm:array [0..7,0..7] of char;
  dlx:array [0..1,0..100] of longint;
  dly:array [0..1,0..100] of longint;
  ans:array [0..100] of char;

procedure addwall(xa,ya,xb,yb:longint);
  var
    i,t:longint;
  begin
    if (xa=xb) then
      begin
        if (ya>yb) then
          begin
            t:=ya;
            ya:=yb;
            yb:=t;
          end;
        for i:=(ya+1) to yb do
          begin
            go[xa,i,xa+1,i]:=false;
            go[xa+1,i,xa,i]:=false;
          end;
      end;
    if (ya=yb) then
      begin
        if (xa>xb) then
          begin
            t:=xa;
            xa:=xb;
            xb:=t;
          end;
        for i:=(xa+1) to xb do
          begin
            go[i,ya,i,ya+1]:=false;
            go[i,ya+1,i,ya]:=false;
          end;
      end;
  end;

begin
  readln(x1,y1);
  while ((x1>0) or (y1>0)) do
    begin
      readln(x2,y2);
      fillchar(go,sizeof(go),true);
      fillchar(tm,sizeof(tm),0);
      fillchar(dlx,sizeof(dlx),0);
      fillchar(dly,sizeof(dly),0);
      for i:=1 to 3 do
        begin
          readln(xw1,yw1,xw2,yw2);
          addwall(xw1,yw1,xw2,yw2);
        end;
      p:=0;
      px:=1;
      dlx[0,0]:=1;
      dlx[0,1]:=x1;
      dly[0,1]:=y1;
      while (ord(tm[x2,y2])<20) do
        begin
          for i:=1 to dlx[p,0] do
            begin
              xt:=dlx[p,i];
              yt:=dly[p,i];
              if (xt+1<=6) and (ord(tm[xt+1,yt])<20) and go[xt,yt,xt+1,yt]
                then
                  begin
                    tm[xt+1,yt]:='E';
                    inc(dlx[px,0]);
                    dlx[px,dlx[px,0]]:=xt+1;
                    dly[px,dlx[px,0]]:=yt;
                  end;
              if (xt-1>0) and (ord(tm[xt-1,yt])<20) and go[xt-1,yt,xt,yt]
                then
                  begin
                    tm[xt-1,yt]:='W';
                    inc(dlx[px,0]);
                    dlx[px,dlx[px,0]]:=xt-1;
                    dly[px,dlx[px,0]]:=yt;
                  end;
              if (yt+1<=6) and (ord(tm[xt,yt+1])<20) and go[xt,yt,xt,yt+1]
                then
                  begin
                    tm[xt,yt+1]:='S';
                    inc(dlx[px,0]);
                    dlx[px,dlx[px,0]]:=xt;
                    dly[px,dlx[px,0]]:=yt+1;
                  end;
              if (yt-1>0) and (ord(tm[xt,yt-1])<20) and go[xt,yt-1,xt,yt]
                then
                  begin
                    tm[xt,yt-1]:='N';
                    inc(dlx[px,0]);
                    dlx[px,dlx[px,0]]:=xt;
                    dly[px,dlx[px,0]]:=yt-1;
                  end;
            end;
          p:=p xor 1;
          px:=px xor 1;
          dlx[px,0]:=0;
        end;
      xt:=x2;yt:=y2;
      ansn:=0;
      while ((xt<>x1) or (yt<>y1)) do
        begin
          inc(ansn);
          ans[ansn]:=tm[xt,yt];
          if (ans[ansn]='E') then xt:=xt-1;
          if (ans[ansn]='N') then yt:=yt+1;
          if (ans[ansn]='W') then xt:=xt+1;
          if (ans[ansn]='S') then yt:=yt-1;
        end;
      for i:=ansn downto 1 do
        write(ans[i]);
      writeln;
      read(x1,y1);
    end;
end.

