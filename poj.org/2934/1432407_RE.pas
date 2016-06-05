const
  tp=30047;

type
  node=record
         st:string;
         p:longint;
       end;
  node2=record
         sts:longint;
         st:string;
         p:longint;
       end;

var
  i,n,j,h,k,fre,frem,ret,mmn:longint;
  flag:boolean;
  st,stp:string;
  hxp:array [0..3000000] of longint;
  hx:array [0..10002] of node2;
  hxpm:array [0..3000000] of longint;
  hxm:array [0..30002] of node2;
  stt:array [0..10000] of string;

function calchx(var st:string):longint;
  var
    i,s,n:longint;
  begin
    n:=length(st);
    s:=0;
    for i:=1 to n do
      s:=(s*s+ord(st[i])) mod tp;
    s:=s+n*100000;
    calchx:=s;
  end;

procedure addhx(var st:string;stt:longint);
  var
    i,s,p,pp:longint;
  begin
    s:=calchx(st);
    p:=hxp[s];
    inc(fre);
    if (p=0) then
      begin
        hxp[s]:=fre;
        hx[fre].st:=st;
        hx[fre].sts:=stt;
        hx[fre].p:=0;
        exit;
      end;
    pp:=p;
    p:=hx[p].p;
    while (p>0) do
      begin
        pp:=p;
        p:=hx[p].p;
      end;
    hx[pp].p:=fre;
    hx[fre].st:=st;
    hx[fre].sts:=stt;
    hx[fre].p:=0;
  end;

function findhx(st:string):longint;
  var
    p,s:longint;
  begin
    s:=calchx(st);
    if hxp[s]=0 then exit(0);
    p:=hxp[s];
    while (p>0) do
      if (hx[p].st=st) then exit(hx[p].sts) else p:=hx[p].p;
    exit(0);
  end;

procedure addhxm(var st:string;sts:longint);
  var
    i,s,p,pp:longint;
  begin
    s:=calchx(st);
    p:=hxpm[s];
    inc(frem);
    if (p=0) then
      begin
        hxpm[s]:=frem;
        hxm[frem].st:=st;
        hxm[frem].sts:=sts;
        hxm[frem].p:=0;
        exit;
      end;
    pp:=p;
    p:=hxm[p].p;
    while (p>0) do
      begin
        pp:=p;
        p:=hxm[p].p;
      end;
    hxm[pp].p:=frem;
    hxm[frem].st:=st;
    hxm[frem].sts:=sts;
    hxm[frem].p:=0;
  end;

function findhxm(st:string):longint;
  var
    p,s:longint;
  begin
    s:=calchx(st);
    if hxpm[s]=0 then exit(0);
    p:=hxpm[s];
    while (p>0) do
      if (hxm[p].st=st) then exit(hxm[p].sts) else p:=hxm[p].p;
    exit(0);
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(stt[i]);
      addhx(stt[i],i);
      for j:=1 to length(stt[i]) do
        begin
          stp:=stt[i];
          delete(stp,j,1);
          addhxm(stp,i);
        end;
    end;
  readln(n);
  for i:=1 to n do
    begin
      mmn:=1000000;
      readln(st);
      flag:=false;
      write(st);
      if (findhx(st)>0) then
        begin
          writeln(' is correct');
          continue;
        end;
      ret:=findhxm(st);
      if (ret>0) and (ret<mmn) then mmn:=ret;
      for j:=1 to length(st) do
        begin
          stp:=st;
          delete(stp,j,1);
          ret:=findhx(stp);
          if (ret>0) and (ret<mmn) then mmn:=ret;
        end;
      for j:=1 to length(st) do
        begin
          for h:=97 to 122 do
            begin
              stp:=st;
              stp[j]:=chr(h);
              ret:=findhx(stp);
              if (ret>0) and (ret<mmn) then mmn:=ret;
            end;
        end;
      for j:=2 to length(st) do
        begin
          stp:=st;
          stp[j]:=st[j-1];
          stp[j-1]:=st[j];
          ret:=findhx(stp);
          if (ret>0) and (ret<mmn) then mmn:=ret;
        end;
      if (mmn<50000) then
          writeln(' is a misspelling of ',stt[mmn])
        else
          writeln(' is unknown');
    end;
end.


