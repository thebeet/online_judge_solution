var
 i,sum,n,k,a,b:longint;
 ff:boolean;
begin
 ff:=true;
 readln(n);
 for i:=1 to n do
  begin
   readln(k);
   if (k=0) then begin write('0');i:=i div k;end else begin
   k:=(k-1)*2;
   a:=trunc(sqrt(k));
   if ff then ff:=false else write(' ');
   if (k=(a*(a+1))) then write('1') else write('0');
  end;end;
 writeln;
end.