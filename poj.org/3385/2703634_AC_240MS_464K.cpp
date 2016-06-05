#include <stdio.h>
int b[100010];int main(){int i,n,m,d,s(0);scanf("%d%d",&n,&d);for (i=0;i<n;++i){scanf("%d",&m);if(b[m]==d){b[m]=2;++s;continue;}else ++b[m];continue;}printf("%d\n",s);return 0;}
