var
 i,n,m,k,a,t,ln,p,j:longint;
 bin2:array [0..50] of longint;
function mi_mod(nx,k:longint):longint;
 var
  i,ans:longint;
 begin
  ans:=1;
  for i:=ln downto 1 do
   if (bin2[i]=1)
    then
     ans:=(((ans*ans) mod k)*nx) mod k
    else
     ans:=(ans*ans) mod k;
  mi_mod:=ans;
 end;
begin
 read(k);
 for i:=1 to k do
  begin
   read(a,n);
   if (n=2) then writeln('1')
            else
             begin
              ln:=0;
              t:=(n-1) shr 1;
              while (t>0) do
               begin
                inc(ln);
                bin2[ln]:=t mod 2;
                t:=t shr 1;
               end;
              p:=mi_mod(a,n);
              if (p<>1) then writeln('No root')
                        else
                          if ((n+1) mod 4=0)
                           then
                            begin
                             ln:=0;
                             t:=(n+1) shr 2;
                             while (t>0) do
                              begin
                               inc(ln);
                               bin2[ln]:=t mod 2;
                               t:=t shr 1;
                              end;
                             p:=mi_mod(a,n);
                             if (p<(n shr 1)) then writeln(p,' ',n-p)
                                              else writeln(n-p,' ',p);
                            end
                           else
                            for j:=1 to n do
                             if (((j*j) mod n)=a) then begin writeln(j,' ',n-j);break;end;

             end;
  end;
end.
