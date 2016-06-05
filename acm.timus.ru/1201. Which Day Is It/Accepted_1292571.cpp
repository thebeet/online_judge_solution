#include <stdio.h>

bool vy(long yyy)
{
	if (((yyy&3)==0) && (((yyy%100)!=0) || ((yyy%400)==0)))
		return true;
	else
		return false;
}

int main()
{
	long i,y,m,d,yy,mm,w,n,t;
	w=5;
	scanf("%d%d%d",&d,&m,&y);
	for (yy=1600;yy<y;yy++)
	{
		if (vy(yy))
			w=(w+366)%7;
		else
			w=(w+365)%7;
	}
	for (mm=1;mm<m;mm++)
	{
		if (mm==2)
		{
			if (vy(yy))
				w=(w+1)%7;
			continue;
		}
		if ((mm==4) || (mm==6) || (mm==9) || (mm==11)) 
		{
			w=(w+2)%7;
			continue;
		}
		w=(w+3)%7;
	}
	if (m==2)
	{
		if (vy(yy))
			n=29;
		else
			n=28;
	}
	if ((m==4) || (m==6) || (m==9) || (m==11)) 
		n=30;
	if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)) 
		n=31;
	for (i=1;i<=7;i++)
	{
		if (i==1) printf("mon");
		if (i==2) printf("tue");
		if (i==3) printf("wed");
		if (i==4) printf("thu");
		if (i==5) printf("fri");
		if (i==6) printf("sat");
		if (i==7) printf("sun");
		t=i-w;
		while (t<=n)
		{
			if (t<=0) printf("     ");
			else
			{
				if (t==d)
				{
					printf(" [");
					if (t<10) printf(" ");
					printf("%d",t);
					printf("]");
				}
				else
				{
					printf("  ");
					if (t<10) printf(" ");
					printf("%d",t);
					printf(" ");
				}
			}
			t+=7;
		}
		printf("\n");
	}
	return 0;
}



