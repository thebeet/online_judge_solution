CONST
 max=30000;
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
  if ((p.y<n) and readbit(map,p.x,p.