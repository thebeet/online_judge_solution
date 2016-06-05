#include <stdio.h>
#include <memory.h>

long ti,i,n,j,p,k;
char inp[10];
__int64 a[10];
__int64 mn[10],mx[10],s,q,tn,tm,pn,pm;
bool flag;

int main()
{
	scanf("%d",&n);
	ti=0;
	while (n>0)
	{
		ti++;
		memset(inp,0,sizeof(inp));
		memset(a,0,sizeof(a));
		memset(mn,0,sizeof(mn));
		memset(mx,0,sizeof(mx));
		s=1000;
		for (i=1;i<=n;i++)
		{
			scanf("%s",&inp);
			j=0;
			p=100;
			while (inp[j]>20)
			{
				if (inp[j]=='.') 
					p=j;
				else
					a[i]=a[i]*10+inp[j]-48;
				j++;
			}
			a[i]*=10;
			mn[i]=(a[i]-5);
			mx[i]=(a[i]+5);
		}
		for (k=p+1;k<j;k++)
			s*=10;
		for (q=1;q<=9999;q++)
		{
			flag=true;
			tn=0;tm=0;
			for (k=1;k<=n;k++)
			{
				pn=(mn[k]*q/s);
				if (((mn[k]*q)%s)!=0) pn++;
				pm=(mx[k]*q/s);
				if (((mx[k]*q)%s)==0) pm--;
				if (pn>pm)
				{
					flag=false;
					break;
				}
				tn+=pn;
				tm+=pm;
			}
			if (flag==false) continue;
			if ((tn<=q) && (tm>=q))
				break;
		}
		printf("Case %d: ",ti);
		if (q<10000) printf("%I64d\n",q);
		else printf("error\n");
		scanf("%d",&n);
	}
	return 0;
}
