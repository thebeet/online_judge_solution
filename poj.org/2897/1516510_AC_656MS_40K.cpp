#include <stdio.h>
#include <memory.h>

long hp[2000];
long hpt[2000];

int main()
{
	long ti,tn,i,j,n,m;
	bool flag;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d",&m,&n);
		flag=false;
		hpt[0]=1;
		hpt[1]=n;
		for (i=1;i<=1000;i++)
		{
			memset(hp,0,sizeof(hp));
			hp[0]=hpt[0];
			for (j=1;j<=hpt[0];j++)
				hp[j]=hpt[j]*m;
			for (j=1;j<=hp[0];j++)
			{
				hp[j+1]+=hp[j]/10;
				hp[j]%=10;
			}
			while (hp[hp[0]+1])
			{
				hp[0]++;
				hp[hp[0]+1]+=hp[hp[0]]/10;
				hp[hp[0]]%=10;
			}
			if ((hpt[0]==hp[0]) && (hp[hp[0]]==n) && (hpt[hpt[0]]!=0))
			{
				flag=true;
				break;
			}
			else
			{
				hpt[0]++;
				hpt[hpt[0]]=hp[hpt[0]-1];
			}
		}
		if (flag) 
		{
			for (i=hpt[0];i>0;i--)
				printf("%d",hpt[i]);
			printf("\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
			

	