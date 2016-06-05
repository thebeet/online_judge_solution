#include <stdio.h>
#include <memory.h>

#define INT __int64

INT ss[500];

INT dd[500][500];

void add(INT n,INT p)
{
	INT i;
	for (i=2;i*i<=n;i++)
		if ((n%i)==0)
		{
			n/=i;
			dd[p][i]++;
			i--;
		}
	if (n!=1) dd[p][n]++;
}

int main()
{
	INT i,j,n,m,s;
	bool flag;
	memset(dd,0,sizeof(dd));
	memset(ss,0,sizeof(ss));
	for (i=2;i<=500;i++)
	{
		flag=true;
		for (j=2;j*j<=i;j++)
			if ((i%j)==0)
			{
				flag=false;
				break;
			}
		if (flag)
		{
			ss[0]++;
			ss[ss[0]]=i;
		}
	}
	for (i=1;i<=431;i++)
		dd[0][i]=-1;
	for (i=1;i<=431;i++)
	{
		memcpy(dd[i],dd[i-1],sizeof(dd[i-1]));
		add(i,i);
	}
	while (scanf("%I64d%I64d",&n,&m)!=EOF)
	{
		s=1;
		i=1;
		while (ss[i]<=n)
		{
			s*=(dd[n][ss[i]]-dd[m][ss[i]]-dd[n-m][ss[i]]);
			i++;
		}
		printf("%I64d\n",s);
	}
	return 0;
}
