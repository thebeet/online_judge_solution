Var
X , Y , K : Longint;
Procedure Init;
Begin
Readln ( X , Y);
K:=1;
End;
Procedure Work;
Var
X1 , Y1 , Temp , Temp1 ,T : Longint;
Begin
Repeat
Inc(K);
X1 := X; Y1:= Y;
Repeat
Temp:=Y1 Mod K;
Repeat
Temp1:= X1 Mod K;
X1 := X1 Div K;
If Temp1=Temp Then Y1:=Y1 Div K;
Until (Temp=Temp1)Or(X1<=Y1);
Until (Y1=0)Or(X1<=Y1);
Until (Y1=0)or(K>X)or(X1=Y1);
If K<=X Then Writeln(K)
Else Writeln('No solution');
End;
Begin
Init;
Work;
End.