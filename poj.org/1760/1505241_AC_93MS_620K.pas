{$R-}
type
 p=^node;
 node=record
       n:string[8];
       c,b:p;
      end;
var
 i,n:longint;
 name:string;
 nw,root:p;
function insert(root:p;n:string[8]):p;
 var
  tmp:p;
 begin
  if (root^.c=nil)
   then
    begin
     new(nw);
     nw^.n:=n;
     nw^.c:=nil;
     nw^.b:=nil;
     root^.c:=nw;
     insert:=nw;
     exit;
    end;
  if (n<root^.c^.n)
   then
    begin
     new(nw);
     nw^.b:=root^.c;
     nw^.n:=n;
     nw^.c:=nil;
     root^.c:=nw;
     insert:=nw;
     exit;
    end;
  if (n=root^.c^.n)
   then
    begin
     insert:=root^.c;
     exit;
    end;
  tmp:=root^.c;
  while (tmp^.b<>nil) do
   begin
    if (n<tmp^.b^.n)
     then
      begin
       new(nw);
       nw^.b:=tmp^.b;
       nw^.n:=n;
       nw^.c:=nil;
       tmp^.b:=nw;
       insert:=nw;
       exit;
      end;
    if (n=tmp^.b^.n)
     then
      begin
       insert:=tmp^.b;
       exit;
      end;
    tmp:=tmp^.b;
   end;
  new(nw);
  nw^.n:=n;
  nw^.c:=nil;
  nw^.b:=nil;
  tmp^.b:=nw;
  insert:=nw;
 end;
procedure fx(path:string);
 var
  i,p0,p1:longint;
  str:string[8];
  tmp:p;
 begin
  tmp:=root;
  p1:=1;
  p0:=pos('\',path);
  if p0=0 then p0:=length(path)+1
          else path[p0]:=' ';
  str:=copy(path,p1,p0-p1);
  p1:=p0+1;
  tmp:=insert(tmp,str);
  while (p0<>length(path)+1) do
   begin
    p0:=pos('\',path);
    if p0=0 then p0:=length(path)+1
            else path[p0]:=' ';
    str:=copy(path,p1,p0-p1);
    p1:=p0+1;
    tmp:=insert(tmp,str);
   end;
 end;
procedure out(root:p;s:longint);
 var
  i:longint;
 begin
  for i:=1 to s do
   write(' ');
  if (s>-1) then writeln(root^.n);
  if (root^.c<>nil)
   then
     out(root^.c,s+1);
  if (root^.b<>nil)
   then
     out(root^.b,s);
 end;
begin
 readln(n);
 new(root);
 root^.n:='';
 root^.c:=nil;
 root^.b:=nil;
 for i:=1 to n do
  begin
   readln(name);
   fx(name);
  end;
 out(root,-1);
end.
