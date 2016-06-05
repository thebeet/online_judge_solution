type
  node=^bs;
  bs=record
       b:longint;
       w:longint;
       sp:longint;
       n:node;
     end;

var
  ti,i,j,s,b,w:longint;
  ch:char;
  tn,head,ttt:node;

function pkup(nn:node;ww,slf:longint):longint;
  var
    pp,tt:node;
  begin
    if nn=nil then exit;
    if (nn^.sp>=ww) then begin nn^.sp:=nn^.sp-ww;exit(0);end;
    ww:=ww-nn^.sp;
    slf:=slf-nn^.w;
    pkup:=0;
    if (slf>=0) then begin if pkup(nn^.n,ww,slf)=1 then nn^.n:=nil;end
             else begin
                    tt:=nn;
                    while (nn<>nil) do
                      begin
                        nn:=tt^.n;
                        dispose(tt);
                        tt:=nn;
                      end;
                    pkup:=1;
                  end;
 end;

function removebook(head:node;b:longint):node;
  var
    tt:node;
  begin
    removebook:=nil;
    if head=nil then exit(nil);
    tt:=head;
    if (head^.b=b) then
      begin
        if (head^.n<>nil) then head^.n^.sp:=head^.n^.sp+head^.sp+head^.w;
        tt:=head;
        head:=head^.n;
        dispose(tt);
        removebook:=head;
      end
      else
        begin
          head^.n:=removebook(head^.n,b);
          removebook:=head;
        end;
  end;

procedure out(head:node);
  begin
    if head=nil then exit;
    write(' ',head^.b);
    out(head^.n);
  end;

begin
  readln(s);
  ti:=0;
  while (s>0) do
    begin
      inc(ti);
      read(ch);
      {new(head);
      head^.b:=0;head^.w:=0;head^.sp:=s;head^.n:=n;}
      head:=nil;
      while (ch<>'E') do
        begin
          if (ch='R')
            then
              begin
                readln(b);
                head:=removebook(head,b);
              end;
          if (ch='A')
            then
              begin
                readln(b,w);
                new(tn);
                tn^.b:=b;
                tn^.w:=w;
                tn^.n:=head;
                tn^.sp:=0;
                head:=tn;
                if pkup(head^.n,w,s-w)=1 then head^.n:=nil;
                {out(head);
                writeln;}
              end;
          read(ch);
        end;
      readln;
      write('PROBLEM ',ti,':');
      out(head);
      writeln;
      readln(s);
    end;
end.
