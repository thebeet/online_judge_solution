VAR
 CH:CHAR;
BEGIN
 CH:='''';
 WRITELN('A="',CH,'";B=',CH,'"',CH,';C="A=;B=;C=;D=";D=";?$(C,1,2)+B+A+B+$(C,3,3)+A+B+A+$(C,6,3)+B+C+B+$(C,9,3)+B+D+B+D";?$(C,1,2)+B+A+B+$(C,3,3)+A+B+A+$(C,6,3)+B+C+B+$(C,9,3)+B+D+B+D');
END.