type
 path=record
       x,y:longint;
      end;
var
 i,n,j,m,k,w:longint;
 dp,dp1:array [0..1000] of longint;
 ps:array [0..100] of path;
 s:real;
function ex(x,y:longint):boolean;
 var
  i:longint;
 begin
  for i:=1 to k do
   if (ps[i].x=x) and (ps[i].y=y) then begin ex:=true;exit;end;
  ex:=false;
 end;
begin
 read(n,m);
 read(k);
 for i:=1 to k do
  read(ps[i].x,ps[i].y);
 fillchar(dp,sizeof(dp),0);
 for j:=1 to m do
  begin
   dp1[0]:=0;
   for i:=1 to n do
    begin
     if ex(i,j) then w:=dp[i-1]+1 else w:=-1;
     if w>dp[i] then dp1[i]:=w else dp1[i]:=dp[i];
     if dp1[i]<dp1[i-1] then dp1[i]:=dp1[i-1];
    end;
   dp:=dp1;
  end;
 s:=sqrt(20000)*dp[n]+(n+m-dp[n]*2)*100;
 writeln(s:0:0);
end.
