var
  tm:array [1..9,1..9] of longint;
  sr,sl,r,l:array [1..9] of longint;
  spp,pp:array [1..3,1..3] of longint;
  ti,tn,i,j,n,m:longint;
  ch:char;

procedure check;
  var
    i,j,s,p:longint;
  begin
    for i:=1 to 9 do
      begin
        for j:=1 to 9 do
          begin
            if (tm[i,j]=0) then inc(r[i]);
            sr[i]:=sr[i]+tm[i,j];
          end;
        for j:=1 to 9 do
          begin
            if (tm[j,i]=0) then inc(l[i]);
            sl[i]:=sl[i]+tm[j,i];
          end;
      end;
   for i:=1 to 9 do
     for j:=1 to 9 do
       begin
         if (tm[i,j]=0) then inc(pp[((i-1) div 3)+1,((j-1) div 3)+1]);
         spp[((i-1) div 3)+1,((j-1) div 3)+1]:=spp[((i-1) div 3)+1,((j-1) div 3)+1]+tm[i,j];
       end;
  end;

begin
  readln(tn);
  for ti:=1 to tn do
    begin
      fillchar(tm,sizeof(tm),0);
      fillchar(pp,sizeof(pp),0);
      fillchar(l,sizeof(l),0);
      fillchar(r,sizeof(r),0);
      fillchar(sl,sizeof(sl),0);
      fillchar(sr,sizeof(sr),0);
      fillchar(spp,sizeof(spp),0);
      writeln('Scenario #',ti,':');
      for i:=1 to 9 do
        begin
          for j:=1 to 9 do
            begin
              read(ch);
              tm[i,j]:=ord(ch)-48;
            end;
          readln;
        end;
  if (ti<tn) then readln;
  check;
  i:=0;
  while (i<9) do
    begin
    inc(i);
    j:=0;
    while (j<9) do
    begin
    inc(j);
      if (tm[i,j]=0)
        then
          begin
            if (r[i]=1)
              then
                begin
                  tm[i,j]:=45-sr[i];
                  r[i]:=0;
                  dec(l[j]);
                  sl[j]:=sl[j]+tm[i,j];
                  dec(pp[((i-1) div 3)+1,((j-1) div 3)+1]);
                  spp[((i-1) div 3)+1,((j-1) div 3)+1]:=spp[((i-1) div 3)+1,((j-1) div 3)+1]+tm[i,j];
                  i:=1;j:=0;
                  continue;
                end;
            if (l[j]=1)
              then
                begin
                  tm[i,j]:=45-sl[j];
                  l[j]:=0;
                  dec(r[i]);
                  sr[i]:=sr[i]+tm[i,j];
                  dec(pp[((i-1) div 3)+1,((j-1) div 3)+1]);
                  spp[((i-1) div 3)+1,((j-1) div 3)+1]:=spp[((i-1) div 3)+1,((j-1) div 3)+1]+tm[i,j];
                  i:=1;j:=0;
                  continue;
                end;
            if (pp[((i-1) div 3)+1,((j-1) div 3)+1]=1)
              then
                begin
                  tm[i,j]:=45-spp[((i-1) div 3)+1,((j-1) div 3)+1];
                  pp[((i-1) div 3)+1,((j-1) div 3)+1]:=0;
                  dec(r[i]);
                  sr[i]:=sr[i]+tm[i,j];
                  dec(l[j]);
                  sl[j]:=sl[j]+tm[i,j];
                  i:=1;j:=0;
                  continue;
                end;
          end;
    end;
  end;
  for i:=1 to 9 do
    begin
      for j:=1 to 9 do
        write(tm[i,j]);
      writeln;
    end;
  writeln;
  end;
end.

