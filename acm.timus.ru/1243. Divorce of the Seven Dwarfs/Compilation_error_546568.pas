var
 i,n:longint;
 ch:char;
 ts:snum;
 str:string;
begin
 ts:=['0'..'9'];
 n:=0;
 readln(str);
 for i:=1 to length(str) do
  begin
   ch:=str[i];
   n:=(n*10+((ord(ch)-48) mod 10))mod 7;
  end;
 writeln(n);
end.
