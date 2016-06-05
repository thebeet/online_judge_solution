#include <stdio.h>
#include <memory.h>

bool u[1000001];
long m[301];

int main()
{
	long ti,tn,i,n,k,j,t;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		memset(u,false,sizeof(u));
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&m[i]);
			for (j=1;j<i;j++)
			{
				t=m[i]-m[j];
				if (t<0) t=-t;
				u[1]=true;
				for (k=2;k*k<=t;k++)
					if ((t%k)==0)
					{
						u[k]=true;
						u[t/k]=true;
					}
				u[t]=true;
			}
		}
		i=1;
		while (u[i])
			i++;
		printf("%d\n",i);
	}
	return 0;
}

				

	
		