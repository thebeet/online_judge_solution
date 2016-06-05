#include <stdio.h>

#define minn 0.0000000001

int main()
{
	long i,j,s;
	long x1,x2,x3,y1,y2,y3,p2t,p3t;
	double x[5],y[5];
	double p2,p3,t;
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	while ((x1!=0)||(y1!=0)||(x2!=0)||(y2!=0)||(x3!=0)||(y3!=0))
	{
		x[1]=x1;
		x[2]=x2;
		x[3]=x3;
		y[1]=y1;
		y[2]=y2;
		y[3]=y3;
		for (i=2;i<=3;i++)
			for (j=1;j<i;j++)
				if (x[j]>x[i])
				{
					t=x[j];
					x[j]=x[i];
					x[i]=t;
					t=y[j];
					y[j]=y[i];
					y[i]=t;
				}
		s=0;
		for (i=1;i<x[2]-x[1]-minn;i++)
		{
			p2=y[1]+(y[2]-y[1])/(x[2]-x[1])*i;
			p3=y[1]+(y[3]-y[1])/(x[3]-x[1])*i;
			if (p2>p3)
			{
				p2-=minn;
				p3+=minn;
				p2t=long(p2);
				p3t=long(p3);
				if (p2>p3) s=s+p2t-p3t;
			}
			else
			{
				p2+=minn;
				p3-=minn;
				p2t=long(p2);
				p3t=long(p3);
				if (p3>p2) s=s+p3t-p2t;
			}
		}
		for (i=long(x[2]-x[1]+minn);i<x[3]-x[1]-minn;i++)
		{
			p2=y[2]+(y[3]-y[2])/(x[3]-x[2])*(i-(x[2]-x[1]));
			p3=y[1]+(y[3]-y[1])/(x[3]-x[1])*i;
			if (p2>p3)
			{
				p2-=minn;
				p3+=minn;
				p2t=long(p2);
				p3t=long(p3);
				if (p2>p3) s=s+p2t-p3t;
			}
			else
			{
				p2+=minn;
				p3-=minn;
				p2t=long(p2);
				p3t=long(p3);
				if (p3>p2) s=s+p3t-p2t;
			}
		}
		if (((x[2]-x[1])<minn) && ((x[3]-x[2])>minn))
		{
			p2=y[1];
			p3=y[2];
			if (p2>p3)
			{
				p2-=minn;
				p3+=minn;
				p2t=long(p2);
				p3t=long(p3);
				if (p2>p3) s=s-p2t+p3t;
			}
			else
			{
				p2+=minn;
				p3-=minn;
				p2t=long(p2);
				p3t=long(p3);
				if (p3>p2) s=s-p3t+p2t;
			}
		}
		printf("%d\n",s);
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	}
	return 0;
}

		 

