var
  ti,tti,i,j,t,n,m,tt:longint;
  map,mapt:array [0..101,0..101] of longint;
  ch:char;

procedure check(i,j:longint);
  begin
    if (i-1>0) and (((mapt[i-1,j]+1) mod 3)=mapt[i,j]) then begin map[i,j]:=((map[i,j]+2) mod 3);exit;end;
    if (i<n) and (((mapt[i+1,j]+1) mod 3)=mapt[i,j]) then begin map[i,j]:=((map[i,j]+2) mod 3);exit;end;
    if (j-1>0) and (((mapt[i,j-1]+1) mod 3)=mapt[i,j]) then begin map[i,j]:=((map[i,j]+2) mod 3);exit;end;
    if (j<m) and (((mapt[i,j+1]+1) mod 3)=mapt[i,j]) then begin map[i,j]:=((map[i,j]+2) mod 3);exit;end;
  end;


begin
  readln(t);
  for ti:=1 to t do
    begin
      if ti<>1 then writeln;
      fillchar(map,sizeof(map),0);
      readln(n,m,tt);
      for i:=1 to n do
        begin
          for j:=1 to m do
            begin
              read(ch);
              if ch='R' then map[i,j]:=0;
              if ch='S' then map[i,j]:=1;
              if ch='P' then map[i,j]:=2;
            end;
          readln;
        end;
      for tti:=1 to tt do
        begin
          for i:=1 to n do
            for j:=1 to m do
              mapt[i,j]:=map[i,j];
          for i:=1 to n do
            for j:=1 to m do
              check(i,j);
        end;
      for i:=1 to n do
        begin
          for j:=1 to m do
            begin
              if map[i,j]=0 then write('R');
              if map[i,j]=1 then write('S');
              if map[i,j]=2 then write('P');
            end;
          writeln;
        end;
    end;
end.
