type
  p=array [0..18] of longint;

var
  i,j,k,h,n,l,m,p1,p2:longint;
  tm:array [0..20,0..3] of string;
  xx:array [0..20,0..20] of boolean;
  pp1:p;
  ans:longint;

function mx(a,b:byte):byte;
  begin
    if (a>b) then exit(a)
    else exit(b);
  end;

procedure sss(pp:p;st:longint);
  var
    i,j:longint;
    flag:boolean;
  begin
    if (ans<pp[0]) then ans:=pp[0];
    inc(pp[0]);
    for i:=st to n do
      begin
        flag:=true;
        for j:=1 to (pp[0]-1) do
          if xx[i][pp[j]]
            then
              begin
                flag:=false;
                break;
              end;
        if flag
          then
            begin
              pp[pp[0]]:=i;
              sss(pp,i+1);
            end;
      end;
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(tm[i][0]);
      p1:=0;p2:=0;
      for j:=1 to length(tm[i][0]) do
        if (tm[i][0][j]=' ')
          then
            if (p1=0) then p1:=j else p2:=j;
      for j:=1 to 3 do
        tm[i][j]:=tm[i][0];
      delete(tm[i][1],p1,length(tm[i][1])-p1+1);
      delete(tm[i][2],p2,length(tm[i][2])-p2+1);
      delete(tm[i][2],1,p1);
      delete(tm[i][3],1,p2);
    end;
  fillchar(xx,sizeof(xx),false);
  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to 3 do
        for h:=1 to 3 do
          if (tm[i][k]=tm[j][h])
            then
              xx[i][j]:=true;
  pp1[0]:=0;
  ans:=0;
  sss(pp1,1);
  writeln(ans);
end.

