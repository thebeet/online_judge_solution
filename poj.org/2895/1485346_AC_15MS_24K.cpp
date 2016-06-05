#include <stdio.h>

char c[1002];

int main()
{
	long ti,tn,i,s,t1,t2,t;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		s=0;
		scanf("%d%d",&t1,&t2);
		scanf("%c",&c[0]);
		scanf("%c",&c[1]);
		i=1;
		c[0]=100;
		while (c[i]>20)
		{
			if (c[i]==32)
				s+=t1;
			else
			{
				t=0;
				if (c[i]=='S') t++;
				if (c[i]=='Z') t++;
				if (c[i]>='S') c[i]--;
				if (c[i]>='Y') c[i]--;
				c[i]-=65;
				t=t+c[i]%3;
				c[i]/=3;
				s+=(t+1)*t1;
				if (c[i]==c[i-1])
				{
					s+=t2;
				}
			}
			i++;
			scanf("%c",&c[i]);
		}
		printf("%d\n",s);
	}
	return 0;
}
					