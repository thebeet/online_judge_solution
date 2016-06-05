type
 theans=array [0..9] of longint;
var
 i,n,m:longint;
 ans:theans;
procedure onenum(var ans:theans;num:longint);
 var
  t:longint;
 begin
  fillchar(ans,sizeof(ans),0);
  while (num>0) do
   begin
    t:=num mod 10;
    num:=num div 10;
    inc(ans[t]);
   end;
 end;
procedure myadd(var ans1,ans2:theans);
 var
  i:longint;
 begin
  for i:=0 to 9 do
   ans1[i]:=ans2[i]+ans1[i];
 end;
procedure mycf(var ans:theans;num:longint);
 var
  i:longint;
 begin
  for i:=0 to 9 do
   ans[i]:=ans[i]*num;
 end;
procedure fill(var ans:theans;num:longint);
 var
  i:longint;
 begin
  for i:=0 to 9 do
   ans[i]:=num;
 end;
procedure ss(var ans:theans;n:longint);
 var
  i,t1,t2:longint;
  ans1:theans;
 begin
  fillchar(ans1,sizeof(ans1),0);
  fillchar(ans,sizeof(ans),0);
  if n<0 then exit;
  t1:=n div 10;t2:=n mod 10;
  onenum(ans1,t1);
  mycf(ans1,t2+1);
  for i:=1 to t2 do
   inc(ans1[i]);
  myadd(ans,ans1);
  fill(ans1,1);mycf(ans1,t1);
  myadd(ans,ans1);
  fillchar(ans1,sizeof(ans1),0);
  ss(ans1,t1-1);
  mycf(ans1,10);
  myadd(ans,ans1);
 end;
begin
 read(m);
 ss(ans,m);
 for i:=0 to 9 do
  writeln(ans[i]);
end.
