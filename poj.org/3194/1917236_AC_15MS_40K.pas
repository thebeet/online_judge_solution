var
	map:array [0..110,0..110] of longint;
	gone:array [0..110] of boolean;
	i,j,n,x,y:longint;
	ans:boolean;

procedure floodfill(x,y:longint);
var
	t:longint;
begin
	t:=map[x][y];
	map[x][y]:=n;
	if (map[x-1][y]=t) then floodfill(x-1,y);
	if (map[x+1][y]=t) then floodfill(x+1,y);
	if (map[x][y-1]=t) then floodfill(x,y-1);
	if (map[x][y+1]=t) then floodfill(x,y+1);
end;

begin
	readln(n);
	while (n>0) do
	begin
		fillchar(map,sizeof(map),1);
		fillchar(gone,sizeof(gone),false);
		for i:=1 to (n-1) do
		begin
			while (not eoln) do
			begin
				read(x,y);
				map[x][y]:=i;
			end;
			readln;
		end;
		ans:=true;
		for i:=1 to n do
		begin
			for j:=1 to n do
			begin
				if (map[i][j]<n) then
				begin
					if (gone[map[i][j]]) then
					begin
						ans:=false;
						break;
					end
					else
					begin
						gone[map[i][j]]:=true;
						floodfill(i,j);
					end;
				end;
			end;
			if (ans=false) then break;
		end;
		if (ans) then writeln('good')
			  else writeln('wrong');
		readln(n);
	end;
end.

