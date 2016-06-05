var
  i,n1,n2,nn1,nn2,sum,t:longint;
  num1,num2:array [0..40] of longint;

begin
  while true do
    begin
      sum:=0;
      readln(n1,n2);
      fillchar(num1,sizeof(num1),0);
      fillchar(num2,sizeof(num2),0);
      if ((n1=0) and (n2=0)) then break;
      nn1:=0;
      while (n1>0) do
        begin
          inc(nn1);
          num1[nn1]:=n1 mod 10;
          n1:=n1 div 10;
        end;
      nn2:=0;
      while (n2>0) do
        begin
          inc(nn2);
          num2[nn2]:=n2 mod 10;
          n2:=n2 div 10;
        end;
      if (nn2>nn1) then nn1:=nn2;
      t:=0;
      for i:=1 to nn1 do
        begin
          num1[i]:=num1[i]+num2[i]+t;
          if (num1[i]>9) then begin t:=1;inc(sum);end else t:=0;
        end;
      if sum=0 then writeln('No carry operation.')
               else if sum=1 then writeln(sum,' carry operation.')
               else writeln(sum,' carry operations.')

    end;
end.