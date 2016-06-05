#include <stdio.h>

long maxn(long n1,long n2)
{
	if (n1>n2) return n1;
	else return n2;
}

long minn(long n1,long n2)
{
	if (n1<n2) return n1;
	else return n2;
}

int main()
{
	float a,b,l,mx;
	long mn,ma,mb,ua,ub;
	long pa,pb;
	scanf("%f%f",&a,&b);
	scanf("%d",&mn);
	for (ma=0;ma<=mn;ma++)
		if ((ma+ma+1)>=a) break;
	ma=minn(ma,mn);
	for (mb=0;mb<=mn;mb++)
		if ((mb+mb+1)>=b) break;
	mb=minn(mb,mn);
	mx=-1;
	for (ub=0;ub<=mb;ub++)
	{
		ua=minn(mn-ub,ma);
		l=ua*a+ub*b-ua*ua-ub*ub;
		if (l>mx) 
		{
			mx=l;
			pa=ua;
			pb=ub;
		}
	}
	printf("%.2f\n%d %d\n",mx,pa,pb);
	return 0;
}


