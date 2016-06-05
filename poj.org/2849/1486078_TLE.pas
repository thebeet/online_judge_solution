var
  i,j,n,m,l,p,st:longint;
  flag:boolean;
  ch:char;
  arr:array [0..40000] of longint;
  prog:array [0..128002] of char;
  stp:array [0..128002] of longint;
  stt:array [0..128002] of longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      fillchar(stt,sizeof(stt),0);
      fillchar(stp,sizeof(stp),0);
      writeln('PROGRAM #',i,':');
      m:=0;
      flag:=true;
      st:=0;
      while true do
        begin
          read(ch);
          if (ord(ch)=10) then begin read(ch);
          if (ch='e') then begin
                             read(ch);
                             if (ch='n') then
                                           begin
                                             read(ch);
                                             if (ch='d') then
                                                           begin
                                                             read(ch);
                                                             if (ord(ch)=13) then begin
                                                             read(ch);
                                                             break;
                                                             end;
                                                           end;
                                           end;
                           end;
          end;
          if (ch='%')
            then
              begin
                readln;
                continue;
              end;
          if (ch='[')
            then
              begin
                inc(st);
                stt[st]:=m;
              end;
          if (ch=']')
            then
              begin
                stp[stt[st]]:=m;
                dec(st);
                if (st<0) then flag:=false;
              end;
          if ((ch='<') or (ch='>') or (ch='+') or (ch='-') or (ch='.') or (ch='[') or (ch=']'))
            then
              begin
                inc(m);
                prog[m]:=ch;
                continue;
              end;
        end;
      if ((st<>0) or (not flag)) then
                             begin
                               writeln('COMPILE ERROR');
                               continue;
                             end;
      p:=0;st:=0;
      fillchar(arr,sizeof(arr),0);
      fillchar(stt,sizeof(stt),0);
      for j:=1 to m do
        begin
          if (prog[j]='<') then begin p:=(p+1) mod 32768;continue;end;
          if (prog[j]='>') then begin p:=(p+32767) mod 32768;continue;end;
          if (prog[j]='+') then begin arr[p]:=(arr[p]+1) mod 256;continue;end;
          if (prog[j]='-') then begin arr[p]:=(arr[p]+255) mod 256;continue;end;
          if (prog[j]='.') then begin write(chr(arr[p]));continue;end;
          if (prog[j]='[') then
                             begin
                               if (arr[p]=0)
                                 then
                                   j:=stp[j]
                                 else
                                   begin
                                     inc(st);
                                     stt[st]:=j;
                                   end;
                               continue;
                             end;
          if (prog[j]=']') then
                             begin
                               if (arr[p]<>0)
                                 then
                                   j:=stt[st]
                                 else
                                   dec(st);
                               continue;
                             end;
        end;
      writeln;
    end;
end.
