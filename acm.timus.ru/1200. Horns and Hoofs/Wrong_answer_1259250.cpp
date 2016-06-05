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
	float a,b;
	long mn,ma,mb,ua,ub,ta,tb,l,mx;
	long pa,pb;
	scanf("%f%f",&a,&b);
	ta=long(a*100+0.1);
	tb=long(b*100+0.1);
	scanf("%d",&mn);
	for (ma=0;ma<=mn;ma++)
		if ((ma+ma+1)*100>=ta) break;
	ma=minn(ma,mn);
	for (mb=0;mb<=mn;mb++)
		if ((mb+mb+1)*100>=tb) break;
	mb=minn(mb,mn);
	mx=-1;
	for (ua=0;ua<=ma;ua++)
	{
		ub=minn(mn-ua,mb);
		l=ua*ta+ub*tb-100*ua*ua-100*ub*ub;
		if (l>mx) 
		{
			mx=l;
			pa=ua;
			pb=ub;
		}
	}
	printf("%d.",mx/100);
	mx=mx%100;
	if (mx<10) printf("%d",0);
	printf("%d\n",mx);
	printf("%d %d\n",pa,pb);
	return 0;
}


