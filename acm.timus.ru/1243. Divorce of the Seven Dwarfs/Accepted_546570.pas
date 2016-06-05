var
 i,n:longint;
 ch:char;
 str:string;
begin
 n:=0;
 readln(str);
 for i:=1 to length(str) do
  begin
   ch:=str[i];
   n:=(n*10+((ord(ch)-48) mod 10))mod 7;
  end;
 writeln(n);
end.
