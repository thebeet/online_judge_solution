CONST
 max=1000000;
TYPE
 node=record
       x,y:integer;
      end;
 themap=array [0..1000,0..126] of byte;
 duilie=array [0..1,0..max] of node;
var
 map,gone:themap;
 dl:duilie;
 first:node;
 i,j,n,m,x,y,k,d1,k1,l,d2:longint;
 ch:char;
procedure addbit(var map:themap;x,y:longint);
 var
  i,t1,t2,s:longint;
 begin
  t1:=y div 8;
  t2:=y mod 8;
  s:=1;
  s:=s shl t2;
  map[x,t1]:=map[x,t1]+s;
 end;
function readbit(var map:themap;x,y:longint):boolean;
 var
  i,t1,t2,s:longint;
 begin
  t1:=y div 8;
  t2:=y mod 8;
  s:=map[x,t1];
  s:=s shr t2;
  if ((s mod 2)=0) then readbit:=false else readbit:=true;
 end;
procedure BFS(p:node);
 var
  i,n,b,x,y:longint;
 begin
  if ((p.y>1) and readbit(map,p.x,p.y-1) and (readbit(gone,p.x,p.y-1)=false))
   then
    begin
     inc(k);
     dl[d2,k].x:=p.x;
     dl[d2,k].y:=p.y-1;
     addbit(gone,p.x,p.y-1);
    end;
  if ((p.y<n) and readbit(map,p.x,p.y+1) and (readbit(gone,p.x,p.y+1)=false))
   then
    begin
     inc(k);
     dl[d2,k].x:=p.x;
     dl[d2,k].y:=p.y+1;
     addbit(gone,p.x,p.y+1);
    end;
  if ((p.x>1) and readbit(map,p.x-1,p.y) and (readbit(gone,p.x-1,p.y)=false))
   then
    begin
     inc(k);
     dl[d2,k].x:=p.x-1;
     dl[d2,k].y:=p.y;
     addbit(gone,p.x-1,p.y);
    end;
  if ((p.x<m) and readbit(map,p.x+1,p.y) and (readbit(gone,p.x+1,p.y)=false))
   then
    begin
     inc(k);
     dl[d2,k].x:=p.x+1;
     dl[d2,k].y:=p.y;
     addbit(gone,p.x+1,p.y);
    end;
 end;
begin
 fillchar(dl,sizeof(dl),0);
 readln(n,m);
 for i:=1 to m do
  begin
   for j:=1 to n do
    begin
     read(ch);
     if ch='.' then begin addbit(map,i,j);first.x:=i;first.y:=j;end;
    end;
   readln;
  end;
 k:=1;d1:=0;l:=0;d2:=1;
 dl[0,1]:=first;
 while (k>0) do
  begin
   k1:=k;k:=0;
   for i:=1 to k1 do
    bfs(dl[d1,i]);
   d1:=d1 xor 1;
   d2:=d2 xor 1;
   inc(l);
  end;
 d1:=d1 xor 1;
 first:=dl[d1,1];
 fillchar(gone,sizeof(gone),0);
 k:=1;d1:=0;l:=0;d2:=1;
 dl[0,1]:=first;
 while (k>0) do
  begin
   k1:=k;k:=0;
   for i:=1 to k1 do
    bfs(dl[d1,i]);
   d1:=d1 xor 1;
   d2:=d2 xor 1;
   inc(l);
  end;
 writeln(l-1);
end.
