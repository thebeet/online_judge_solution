#include <stdio.h>

int bracket;
int note;
char ch, ch1, ch2;

int main()
{
bracket = 0 ;
note = 0 ;
while (1) {
if ((ch = getchar()) == EOF) {
if (note != 0 || bracket != 0) {
printf("NO\n");
return 0;
}
break;
}
if (ch == '(' && note == 0) {
bracket++;
}
if (ch == '*') {
if (ch1 == '(') {
if (note == 0) bracket--;
if (note == 0) note++;
}
}
if (ch == ')') {
if (ch1 == '*' && note != 0 && ch2 !
= '(') {
note--;
if (note < 0) { printf("NO\n"); 
return 0; }
}
else {
if (note == 0) {
bracket--;
if (bracket < 0) { 
printf("NO\n"); return 0; }
}
}
}
if (ch == ' ' && bracket > 0 && note == 0) { printf
("NO\n"); return 0; }
if (bracket > 0 && note == 0) {
if (ch != '0' && ch != '1' && ch != '2' 
&& ch != '3' && ch != '4' 
&& ch != '5' && ch != '6' && ch !
= '7' && ch != '8' && ch != '9' 
&& ch != '+' && ch != '-' && ch !
= '*' && ch != '/' && ch != '(' 
&& ch != ')' && ch != '=' && ch !
= '\n' && ch != '\r' )
{ printf("NO\n"); return 0; }

}

ch2 = ch1;
ch1 = ch;
}
printf("YES\n");
return 0;
} 