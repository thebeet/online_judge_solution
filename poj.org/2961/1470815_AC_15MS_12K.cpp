#include <stdio.h>

long find(__int64 n,__int64 x,__int64 y)
{
	__int64 p;
	if (n==1) return 1;
	p=n/2;
	if ((x>p) && (y>p)) return -find(p,x-p,y-p);
	if (x>p) x-=p;
	if (y>p) y-=p;
	return find(p,x,y);
}

int main()
{
	long ti,tn;
	__int64 n,x,y,w,h,i,j;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%I64d%I64d%I64d%I64d%I64d",&n,&x,&y,&w,&h);
		for (i=1;i<=h;i++)
		{
			for (j=1;j<w;j++)
				printf("%d ",find(n,x+j,y+i));
			printf("%d\n",find(n,x+w,y+i));
		}
		printf("\n");
	}
	return 0;
}

