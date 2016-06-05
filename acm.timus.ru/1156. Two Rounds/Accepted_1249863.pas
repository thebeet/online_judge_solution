var
  i,j,n,m,a,b,pid,id,n2,am:longint;
  able:array [0..101,0..101] of boolean;
  pairs:array [0..101,0..101,0..1] of longint;
  flag:array [0..101] of byte;
  p:array [0..101] of longint;
  dp:array [0..101,-201..201] of longint;
  ans:array [0..1,0..101] of longint;

procedure add(p,pid:longint);
  var
    i:longint;
  begin
    flag[p]:=pid;
    inc(pairs[id,0,pid]);
    pairs[id,pairs[id,0,pid],pid]:=p;
    for i:=1 to n2 do
      if able[p,i]
        then
          begin
            if (flag[i]=pid) then begin writeln('IMPOSSIBLE');halt;end;
            if (flag[i]=2) then add(i,pid xor 1);
          end;
  end;

begin
  readln(n,m);
  n2:=n shl 1;
  fillchar(able,sizeof(able),false);
  fillchar(flag,sizeof(flag),2);
  fillchar(pairs,sizeof(pairs),0);
  for i:=1 to m do
    begin
      readln(a,b);
      able[a,b]:=true;
      able[b,a]:=true;
    end;
  id:=0;
  for i:=1 to (n shl 1) do