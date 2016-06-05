var
  i,j,n,s:longint;
  m:array [0..5,0..5] of char;
  ans:array [0..5,0..5] of boolean;
  flag:boolean;

begin
  fillchar(ans,sizeof(ans),false);
  n:=4;
  s:=0;
  for i:=1 to n do
    begin
      flag:=false;
      for j:=1 to n do
        begin
          read(m[i,j]);
          if (m[i,j]='+') then flag:=not flag;
        end;
      if flag then
        for j:=1 to n do
          ans[i,j]:=true;
      readln;
    end;
  for j:=1 to n do
    begin
      flag:=false;
      for i:=1 to n do
        if (m[i,j]='+') then flag:=not flag;
      for i:=1 to n do
        begin
          ans[i,j]:=ans[i,j] xor flag xor (m[i,j]='+');
          if ans[i,j] then inc(s);
        end;
    end;
{  if (s>(n*n shr 1))
    then
      begin
        writeln(n*n-s);
        for i:=1 to n do
          for j:=1 to n do
            if (not ans[i,j]) then
              writeln(i,' ',j);
      end
    else
      begin}
        writeln(s);
        for i:=1 to n do
          for j:=1 to n do
            if ans[i,j] then
              writeln(i,' ',j);
{      end;}
end.
