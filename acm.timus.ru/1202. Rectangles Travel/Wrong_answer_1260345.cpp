#include <stdio.h>
int main()
{
	long i,n,s,h;
	long x1,x2,y1,y2,py1,py2;
	scanf("%d",&n);
	scanf("%d%d%d%d",&x1,&py1,&x2,&py2);
	s=0;
	h=1;
	y2=py2;
	for (i=2;i<=n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if (y1>=py2-1)
		{
			printf("-1\n");
			return 0;
		};
		if (y2<=py1+1)
		{
			printf("-1\n");
			return 0;
		};
		if (h<=y1+1)
		{
			s=s+y1+1-h;
			h=y1+1;
		}
		if (h>=y2-1)
		{
			s=s+h-(y2-1);
			h=y2-1;
		}
		py1=y2;
		py2=y2;
	}
	if (h>(y2-1)) s=s+h-(y2-1);
	else s=s+(y2-1)-h;
	s=s+x2-2;
	printf("%d\n",s);
	return 0;
}
	
