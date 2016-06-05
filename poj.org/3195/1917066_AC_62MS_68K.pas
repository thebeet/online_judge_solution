var
	m:longint;
	ans:boolean;
	st:array [0..10000] of longint;
	s:array [0..10000] of longint;
begin
	while (not eof) do
	begin
		ans:=true;
		fillchar(st,sizeof(st),0);
		fillchar(s,sizeof(s),0);
		while (not eoln) do
		begin
			read(m);
			if (m<0) then
			begin
				if ((s[st[0]]>=m) and (st[0]>0)) then 
				begin
					ans:=false;
					break;
				end
				else
				begin
					s[st[0]]:=s[st[0]]-m;
					inc(st[0]);
					st[st[0]]:=m;
					s[st[0]]:=st[st[0]];
				end;
			end
			else
			begin
				if (st[st[0]]=-m) then dec(st[0])
				else
				begin
					ans:=false;
					break;
				end;
			end;
		end;
		if (st[0]<>0) then ans:=false;
		if (ans) then writeln(':-) Matrioshka!')
			 else writeln(':-( Try again.');
		readln;
	end;
end.



				
				


		

