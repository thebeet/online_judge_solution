var
 n,m,sj,so:longint;
 i:char;
 j:array ['A'..'H'] of longint;
procedure tt(f,t,m:char);
 var
  i:longint;
 begin
  if (j[f]>0)
   then
    begin
     for i:=1 to j[f] do
      writeln(m,t,'+');
     for i:=1 to j[f] do
      writeln(f,m,'-');
     j[t]:=j[f]+j[t];
     j[f]:=0;
    end;
 end;
begin
 for i:='A' to 'H' do
  read(j[i]);
 sj:=j['A']+j['C']+j['F']+j['H'];
 so:=j['B']+j['D']+j['E']+j['G'];
 if (sj<>so) then begin writeln('IMPOSSIBLE');exit;end;
 tt('G','C','B');
 tt('H','D','A');
 tt('E','F','B');
 tt('F','E','A');
 tt('D','C','B');
 tt('C','D','A');
 for n:=1 to j['A'] do
  writeln('AB-');
end.