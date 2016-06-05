const
  p=39133;

type
  chs=array [0..250000] of char;

var
  i,n,m,q1,q2,d,p2:longint;
  st1,st2:chs;

function mi_mod(x,t,m:longint):longint;
  var
    i:longint;
    n,s:longint;
    bin2:array [0..50] of longint;
  begin
    fillchar(bin2,sizeof(bin2),0);
    n:=0;
    while (t>0) do
      begin
        inc(n);
        bin2[n]:=t mod 2;
        t:=t div 2;
      end;
    s:=1;
    for i:=n downto 1 do
      if bin2[i]=1
        then
          s:=(((s*s) mod m)*x) mod m
        else
          s:=(s*s) mod m;
    mi_mod:=s;
  end;

function check(d:longint):boolean;
  var
    i,m:longint;
  begin
    for i:=1 to n do
      if (st1[i]<>st2[((i+d-1) mod n)+1]) then exit(false);
    check:=true;
  end;

begin
  readln(n);
  q1:=0;
  q2:=0;
  for i:=1 to n do
    begin
      read(st1[i]);
      q1:=((q1*10)+ord(st1[i])) mod p;
    end;
  readln;
  for i:=1 to n do
    begin
   