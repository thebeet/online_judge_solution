var
 i,s,p:longint;
 LnStr:string;
function tongjichar(var str:string):longint;
 var
  i,s:longint;
 begin
  s:=0;
  for i:=1 to length(str) do
   if (str[i]=chr(34))
    then
     if (i=1) or ((i>1) and (str[i-1]<>'\'))
      then
       inc(s);
  tongjichar:=s;
 end;
begin
 while not eof do
  begin
   readln(lnstr);
   s:=tongjichar(lnstr);
   p:=0;
   for i:=1 to length(lnstr) do
    if (lnstr[i]=chr(34))
     then
      begin
       if (i=1) or ((i>1) and (lnstr[i-1]<>'\'))
        then
         begin
          inc(p);
          if ((s mod 2)=1) and ((s-p)=0) then continue;
          if ((p mod 2)=1) then write(chr(96),chr(96));
          if ((p mod 2)=0) then write(chr(39),chr(39));
         end
        else
         write(chr(34));
      end
     else
      write(lnstr[i]);
   writeln;
  end;
end.
