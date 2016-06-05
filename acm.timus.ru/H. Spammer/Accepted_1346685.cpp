#include <stdio.h>
#include <string.h>

char s[110][110];

int main()
{
	long i,j,n;
	scanf("%d",&n);
	memset(s,0,sizeof(s));
	for (i=1;i<=n;i++)
		scanf("%s",&s[i]);
	for (i=1;i<=n;i++)
		for (j=i+1;j<=n;j++)
			if (strcmp(s[i],s[j])>0)
			{
				memcpy(s[0],s[i],sizeof(s[i]));
				memcpy(s[i],s[j],sizeof(s[i]));
				memcpy(s[j],s[0],sizeof(s[i]));
			}
	for (i=2;i<=n;i++)
		if ((strcmp(s[i],s[i-1])==0) && (strcmp(s[i],s[i-2])!=0))
			printf("%s\n",s[i]);
	return 0;
}
