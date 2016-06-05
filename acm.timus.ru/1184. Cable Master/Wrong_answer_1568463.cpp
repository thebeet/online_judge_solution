#include <stdio.h>
#include <memory.h>

long lengthcable[10010];

int main()
{
	long i,n,m,l_binsearch,m_binsearch,h_binsearch,total;
	double inp;
	scanf("%ld%ld",&n,&m);
	while (n>0)
	{
		memset(lengthcable,0,sizeof(lengthcable));
		for (i=1;i<=n;i++)
		{
			scanf("%lf",&inp);
			lengthcable[i]=(long)(inp*100+0.1);
			lengthcable[0]+=lengthcable[i];
		}
		if (lengthcable[0]<m)
		{
			printf("0.00\n");
		}
		else
		{
			l_binsearch=1;
			h_binsearch=100000001;
			while (l_binsearch+1<h_binsearch)
			{
				m_binsearch=(l_binsearch+h_binsearch)/2;
				total=0;
				for (i=1;i<=n;i++)
				{
					total+=(lengthcable[i]/m_binsearch);
				}
				if (total>=m) l_binsearch=m_binsearch;
				else h_binsearch=m_binsearch;
			}
			printf("%ld.%ld%ld\n",l_binsearch/100,(l_binsearch%100)/10,l_binsearch%10);
		}
break;
		scanf("%ld%ld",&n,&m);

	}
	return 0;
}
