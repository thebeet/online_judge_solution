const
  MAXN = 10001;
var
  A: array[0..MAXN] of integer;
  ans:array [0..10001] of boolean;
  i,N,p,ll,st,ss: integer;
procedure BS(x: integer);
var
  p, q, i, L: integer;
begin
  p := 0;   { Left border of the search  }
  q := N-1; { Right border of the search }
  L := 0;   { Comparison counter         }
  while p <= q do begin
    i := (p + q) div 2;
    inc(L);
    if A[i] = x then begin
      if l=ll then ans[n]:=true;
      exit
    end;
    if x < A[i] then
      q := i - 1
    else
      p := i + 1
  end
end;
begin
 fillchar(ans,sizeof(ans),false);
 readln(p,ll);
 for i:=0 to 10000 do
  a[i]:=i;
 for i:=0 to 10000 do
  begin
   n:=i;
   bs(p);
  end;
 ss:=0;st:=0;
 for i:=0 to 10001 do
  begin
   if ((st=0) and ans[i]) then begin inc(ss);st:=1;continue;end;
   if ((st=1) and (not ans[i])) then begin st:=0;continue;end;
  end;
 writeln(ss);
 st:=0;
 for i:=0 to 10001 do
  begin
   if ((st=0) and ans[i]) then begin st:=1;write(i,' ');continue;end;
   if ((st=1) and (not ans[i])) then begin st:=0;writeln(i-1);continue;end;
  end;
end.
  end;




end.