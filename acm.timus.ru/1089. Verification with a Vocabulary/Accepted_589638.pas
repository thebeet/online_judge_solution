type
 thechs=array [0..1000] of char;
var
 vv:array [0..100] of thechs;
 ln:array [0..100] of longint;
 i,n,m,p,t,j:longint;
 flag:boolean;
 str1:string;
 ch:char;
 st2,st1:thechs;
function check(chs1,chs2:thechs;n:longint):longint;
 var
  i,s:longint;
 begin
  s:=0;
  for i:=1 to n do
   if (chs1[i]<>chs2[i])
    then
     begin
      inc(s);
      if (s=2) then begin check:=2;exit;end;
     end;
  check:=s;
 end;
begin
 readln(str1);
 n:=0;
 while (str1<>'#') do
  begin
   inc(n);
   ln[n]:=length(str1);
   for j:=1 to length(str1) do
    vv[n,j]:=str1[j];
   readln(str1);
  end;
 p:=0;
 m:=0;
 while (not eof) do
  begin
   read(ch);
   if (ch in ['a'..'z'])
    then
     begin
      inc(p);
      st1[p]:=ch;
     end
    else
     begin
      if (p>0) then
       begin
        flag:=false;
        for i:=1 to n do
         if (ln[i]=p) then
         begin
          t:=check(st1,vv[i],p);
          if (t=0) then begin for j:=1 to p do write(vv[i,j]);flag:=true;break;end;
          if (t=1) then begin for j:=1 to p do write(vv[i,j]);inc(m);flag:=true;break;end;
         end;
        if (not flag) then for j:=1 to p do write(st1[j]);
        p:=0;
       end;
      write(ch);
     end;
 end;
 writeln(m);
end.