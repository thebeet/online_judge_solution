type
 node=^pn;
 pn=record
     l,r:node;
     d:longint;
    end;
var
 i,n,m:longint;
 root,nw:node;
 inp:array [0..3000] of longint;
procedure insert(m:longint;root:node);
 begin
  if root^.d<m
   then
    if root^.r<>nil
     then
      insert(m,root^.r)
     else
      begin
       new(nw);
       root^.r:=nw;
       nw^.d:=m;
      end
   else
    if root^.l<>nil
     then
      insert(m,root^.l)
     else
      begin
       new(nw);
       root^.l:=nw;
       nw^.d:=m;
      end;
 end;
procedure out(root:node);
 begin
  if root^.r<>nil then out(root^.r);
  if root^.l<>nil then out(root^.l);
  write(root^.d,' ');
 end;
begin
 read(n);
 for i:=1 to n do
  read(inp[i]);
 new(root);
 root^.d:=inp[n];
 for i:=(n-1) downto 1 do
  insert(inp[i],root);
 out(root);
 writeln;
end.
