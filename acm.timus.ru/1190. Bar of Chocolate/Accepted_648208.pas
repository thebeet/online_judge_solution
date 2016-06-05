var
 a:array[1..5000] of integer;
 n,i:integer;
 max,min:longint;
 summax,summin:longint;
 str:string;
 chislo,code:integer;
begin
 max:=0;
 min:=0;
 Readln(n);
 for i:=1 to n do
  begin
   Readln(str);
   Delete(str,1,pos(' ',str));
   if str[1]='0'
    then
     a[i]:=0
    else
     begin
      delete(str,1,2);
      val(str,chislo,code);
      a[i]:=chislo;
    end;
  end;
 max:=20000;min:=1;
 summax:=0;summin:=0;
 for i:=1 to n do
  if a[i]=0
   then
    summax:=summax+max
   else
    begin
     summax:=summax+a[i];
     max:=a[i];
    end;
 for i:=n downto 1 do
  if a[i]=0
   then
    summin:=summin+min
   else
    begin
     summin:=summin+a[i];
     min:=a[i];
    end;
 if (summin<=10000)and(summax>=10000)
  then
   writeln('YES')
  else
   writeln('NO');
end.