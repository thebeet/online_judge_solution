var
  n,l:qword;
  i:longint;
  bin:array [0..100] of longint;
  st:array [0..100] of string;
  ans:string;

begin
  l:=1;
  st[1]:='1';
  for i:=2 to 41 do
    begin
      l:=l*3;
      str(l,st[i]);
    end;
  st[42]:='36472996377170786403';
  st[43]:='109418989131512359209';
  st[44]:='328256967394537077627';
  st[45]:='984770902183611232881';
  st[46]:='2954312706550833698643';
  st[47]:='8862938119652501095929';
  st[48]:='26588814358957503287787';
  st[49]:='79766443076872509863361';
  st[50]:='239299329230617529590083';
  st[51]:='717897987691852588770249';
  st[52]:='2153693963075557766310747';
  st[53]:='6461081889226673298932241';
  st[54]:='19383245667680019896796723';
  st[55]:='58149737003040059690390169';
  st[56]:='174449211009120179071170507';
  st[57]:='523347633027360537213511521';
  st[58]:='1570042899082081611640534563';
  st[59]:='4710128697246244834921603689';
  st[60]:='14130386091738734504764811067';
  st[61]:='42391158275216203514294433201';
  st[62]:='127173474825648610542883299603';
  st[63]:='381520424476945831628649898809';
  st[64]:='1144561273430837494885949696427';
  readln(n);
  while (n>0) do
    begin
      if (n=1) then
        begin
          writeln('{ }');
          readln(n);
          continue;
        end;
      dec(n);
      bin[0]:=0;
      while (n>0) do
        begin
          inc(bin[0]);
          bin[bin[0]]:=n mod 2;
          n:=n shr 1;
        end;
      ans:='{';
      for i:=1 to bin[0] do
        if (bin[i]=1) then
          ans:=ans+' '+st[i]+',';
      ans[length(ans)]:=' ';
      ans:=ans+'}';
      writeln(ans);
      readln(n);
    end;
end.

