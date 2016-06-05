const
 max=100;
type
 node=^stack;
 stack=record
        d:longint;
        n:node;
       end;
var
 sk:array [1..1000] of node;
 i,n,m,a,b:longint;
 ch1,ch2:char;
procedure push(a,b:longint);
 var
  sss:node;
 begin
  new(sss);
  sss^.d:=b;
  sss^.n:=sk[a];
  sk[a]:=sss;
 end;
function pop(a:longint):longint;
 var
  tmp:node;
 begin
  pop:=sk[a]^.d;
  sk[a]:=sk[a]^.n;
 end;
begin
 readln(n);
 for i:=1 to n do
  begin
   read(ch1,ch2);
   if (ch2='U')
    then
     begin
      read(ch1,ch2);
      readln(a,b);
      push(a,b);
     end
    else
     begin
      read(ch1);
      readln(a);
      writeln(pop(a));
     end;
  end;
end.