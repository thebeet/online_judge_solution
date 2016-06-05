var
 i,h,j,x,y,n,ans:longint;
 ch:char;
begin
 readln(n);
 for i:=1 to n do
  begin
   read(ch);
   readln(x);
   y:=ord(ch)-96;
   ans:=0;
   for j:=1 to 8 do
    case j of
     1:if (((x-1)>0) and ((y-2)>0)) then inc(ans);
     2:if (((x-1)>0) and ((y+2)<9)) then inc(ans);
     3:if (((x-2)>0) and ((y-1)>0)) then inc(ans);
     4:if (((x-2)>0) and ((y+1)<9)) then inc(ans);
     5:if (((x+1)<9) and ((y-2)>0)) then inc(ans);
     6:if (((x+1)<9) and ((y+2)<9)) then inc(ans);
     7:if (((x+2)<9) and ((y-1)>0)) then inc(ans);
     8:if (((x+2)<9) and ((y+1)<9)) then inc(ans);
    end;
   writeln(ans);
  end;
end.