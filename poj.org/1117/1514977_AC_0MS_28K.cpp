#include <stdio.h>
#include <memory.h>

long t[10];
long m[10];
long ans[100];
long an;

int main()
{
	long i,j,k,n,nn,ne,nf,p2,tt;
	scanf("%d",&n);
	t[0]=1;
	m[0]=0;
	for (i=1;i<=9;i++)
	{
		t[i]=t[i-1]*10;
		m[i]=n%t[i];
	}
	an=0;
	memset(ans,0,sizeof(ans));
	nn=n;
	i=0;
	if ((nn%11)<10)
	{
		nf=nn/11*10+nn%11;
		if (nf!=0)
		{
			an++;
			ans[an]=nf;
		}
	}
	nn/=10;
	while (nn>0)
	{
		i++;
		if ((m[i]&1)==0)
		{
			ne=m[i]/2;
			if ((nn%11)<10)
			{
				nf=(nn/11*10+nn%11)*t[i]+ne;
				if (nf!=ne)
				{
					an++;
					ans[an]=nf;
				}
			}
			nn--;
			ne=(t[i]+m[i])/2;
			if ((nn%11)<10)
			{
				nf=(nn/11*10+nn%11)*t[i]+ne;
				if (nf!=ne)
				{
					an++;
					ans[an]=nf;
				}
			}
			nn=(nn+1)/10;
		}
		else
			break;
	}
	for (i=2;i<=an;i++)
		for (j=1;j<i;j++)
			if (ans[i]<ans[j])
			{
				tt=ans[i];
				ans[i]=ans[j];
				ans[j]=tt;
			}
	tt=0;
	for (i=2;i<=an;i++)
		if (ans[i]==ans[i-1])
		{
			tt++;
		}
		else
		{
			ans[i-tt]=ans[i];
		}
	an=an-tt;
	printf("%d\n",an);
	for (i=1;i<=an;i++)
	{
		printf("%d + ",ans[i]);
		k=9;
		p2=n-ans[i];
		while ((ans[i]/t[k])<1) 
			k--;
		k--;
		for (j=k;j>=1;j--)
			if (p2<t[j]) printf("0");
		printf("%d = %d\n",p2,n);
	}
	return 0;
}
