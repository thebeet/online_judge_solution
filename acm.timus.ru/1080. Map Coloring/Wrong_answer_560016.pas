var
 map:array [0..100] of byte;
 i,j,n,t:longint;
 flag:boolean;
begin
 flag:=true;
 readln(n);
 fillchar(map,sizeof(map),2);
 for i:=1 to n do
  begin
   if (map[i]=2) then map[i]:=0;
    read(t);
     while (t<>0) do
      begin
       if ((map[t]=2) and (map[i]=0)) then map[t]:=1;
       if ((map[t]=1) and (map[i]=0)) then map[t]:=1;
       if ((map[t]=0) and (map[i]=0)) then flag:=false;
       if ((map[t]=2) and (map[i]=1)) then map[t]:=0;
       if ((map[t]=1) and (map[i]=1)) then flag:=false;
       if ((map[t]=0) and (map[i]=1)) then map[t]:=0;
       read(t);
      end;
   if (not flag) then break;
  end;
 if flag then for i:=1 to n do write(map[i])
         else write('-1');
end.