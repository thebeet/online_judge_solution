var
 ans:array [0..36] of longint;
 nw:array [0..36] of boolean;
 i,n,m,p,t:longint;
 ch:char;
begin
 fillchar(ans,sizeof(ans),0);
 fillchar(nw,sizeof(nw),true);
 while not eof do
  begin
   read(ch);
   if (ord(ch)>40)
    then
     begin
      if (ch in ['0'..'9']) then t:=(ord(ch)-48) mod 10;
      if (ch in ['A'..'Z']) then t:=ord(ch)-55;
      for i:=2 to t do
       nw[i]:=true;
      for i:=(t+1) to 36 do
       if nw[i] then begin nw[i]:=false;inc(ans[i]);end;
     end
    else
     fillchar(nw,sizeof(nw),true);

  end;
 m:=-1;
 for i:=2 to 36 do
  if m<ans[i] then begin m:=ans[i];p:=i;end;
 writeln(p,' ',m);
end.

