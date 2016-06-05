var
 ch1,ch2:char;
 numset:set of '0'..'9';
 st:array [0..10001] of byte;
 tt:array [0..10050] of char;
 i,n,m,p,ln:longint;
 errflag:boolean;
begin
 fillchar(tt,sizeof(tt),'a');
 numset:=['0'..'9'];
 p:=1;
 ln:=0;
 errflag:=false;
 while (not eof) do
  begin
   inc(ln);
   read(tt[ln]);
   if (ord(tt[ln])<14) then dec(ln);
  end;
 fillchar(st,sizeof(st),0);
 for i:=1 to ln do
   case st[p] of
    0:if (tt[i]='(')
       then
        if tt[i+1]='*'
         then
          begin
           inc(p);
           st[p]:=1;
          end
         else
          begin
           inc(p);
           st[p]:=2;
          end
       else
        if (tt[i]=')')
         then
          begin writeln('NO');exit;end;
    1:if ((tt[i]='*') and (tt[i+1]=')'))
        then
         begin
          dec(p);
          inc(i);
         end;
    2:if (tt[i]=')')
       then
        dec(p)
       else
        begin
         if ((tt[i]<>'=') and (tt[i]<>'+') and (tt[i]<>'-') and (tt[i]<>'/') and (tt[i]<>'*'))
          then
           if (tt[i]<>'(')
            then
             begin
              writeln('NO');
              exit;
             end
            else
             if tt[i+1]='*'
              then
               begin
                inc(p);
                st[p]:=1;
                inc(i);
               end
              else
               begin
                inc(p);
                st[p]:=2;
               end;
        end;
  end;{case}
 if (p<>1) then begin writeln('NO');exit;end;
 writeln('YES');
end.
