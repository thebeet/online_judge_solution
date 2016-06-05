#include <stdio.h>
int main()
{
	int i,j,k,m,n,t;
	scanf("%d%d",&m,&n);
	char s[101][101];
	char tt[101];
	int ss[101];
	int p[101];
	for (i=1;i<=n;i++)
	{
		scanf("%s",&s[i]);
		p[i]=i;
		ss[i]=0;
		for (j=0;j<m;j++)
			for (k=j+1;k<m;k++)
				if (s[i][k]<s[i][j]) ss[i]++;
   	}
	for (i=1;i<=n;i++)
		for (j=i+1;j<=n;j++)
			if (ss[i]>ss[j])
			{
				t=ss[i];
				ss[i]=ss[j];
				ss[j]=t;
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
	for (i=1;i<=n;i++)
		printf("%s\n",s[p[i]]);
	return 0;
}
