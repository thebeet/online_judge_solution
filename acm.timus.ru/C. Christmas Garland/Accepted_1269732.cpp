#include <stdio.h>

char c[100001];
long h[100001];

int main()
{
	long i,j,n,p;
	bool flag;
	scanf("%d",&n);
	scanf("%c",&c[0]);
	h[0]=0;
	for (i=1;i<=n;i++)
	{
		scanf("%c",&c[i]);
		h[i]=h[i-1];
		if (c[i]=='u')
			h[i]++;
		if (c[i]=='d')
			h[i]--;
	}
	flag=false;
	for (i=n-1;i>1;i--)
		if (c[i]!='u')
		{
			if (h[i]<=(n-i-1))
			{
				if (c[i]=='d')
					c[i]='h';
				else
					c[i]='u';
				for (j=i+1;j<=i+h[i];j++)
					c[j]='d';
				p=i+h[i]+1;
				if (((n-p+1)%2)==0)
				{
					for (j=p;j+2<n;j=j+2)
					{
						c[j]='d';
						c[j+1]='u';
					}
					c[n]='d';
					c[n-1]='h';
				}
				else
					for (j=p;j<n;j=j+2)
					{
						c[j]='d';
						c[j+1]='u';
					}
				flag=true;
				break;
			}	
		}
	if (flag)
	{
		for (i=1;i<=n;i++)
			printf("%c",c[i]);
		printf("\n");
	}
	else
		printf("No solution\n");
	return 0;
}
				




		

	

