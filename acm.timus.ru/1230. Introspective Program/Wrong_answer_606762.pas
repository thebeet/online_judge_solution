program IntrospectiveProgram;
var
Stgs: array[1..20] of String;
i, j: Integer;

begin
Stgs[ 1] := '';
Stgs[ 2] := ' WriteLn("program IntrospectiveProgram;");';
Stgs[ 3] := ' WriteLn("var");';
Stgs[ 4] := ' WriteLn(" Stgs: array[1..20] of String;");';
Stgs[ 5] := ' WriteLn(" i, j: Integer;");';
Stgs[ 6] := ' WriteLn;';
Stgs[ 7] := ' WriteLn("begin");';
Stgs[ 8] := '';
Stgs[ 9] := ' for i := 1 to 20 do';
Stgs[10] := ' WriteLn(" Stgs[",i:2,"] := """, Stgs[i], """;");';
Stgs[11] := ' WriteLn;';
Stgs[12] := '';
Stgs[13] := ' for i := 1 to 20 do';
Stgs[14] := ' for j := 1 to Length(Stgs[i]) do';
Stgs[15] := ' if Stgs[i][j] = Chr(34) then';
Stgs[16] := ' Stgs[i][j] := Chr(39);';
Stgs[17] := '';
Stgs[18] := ' for i := 1 to 20 do';
Stgs[19] := ' WriteLn(Stgs[i]);';
Stgs[20] := 'end.';


WriteLn('program IntrospectiveProgram;');
WriteLn('var');
WriteLn(' Stgs: array[1..20] of String;');
WriteLn(' i, j: Integer;');
WriteLn;
WriteLn('begin');

for i := 1 to 20 do
WriteLn(' Stgs[',i:2,'] := ''', Stgs[i], ''';');
WriteLn;

for i := 1 to 20 do
for j := 1 to Length(Stgs[i]) do
if Stgs[i][j] = Chr(34) then
Stgs[i][j] := Chr(39);

for i := 1 to 20 do
WriteLn(Stgs[i]);
end.
