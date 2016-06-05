#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

char tm[10][10];
long sw[10][10][10][10];
long x[70];
long y[70];
long xm,ym,xa1,xa2,ya1,ya2,tx,ty;
long s;
bool flag;

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

void check(long tx,long ty)
{
	if (tm[tx][ty]=='P')
	{
		printf("You can escape.\n");
		flag=true;
		return;
	}
	if ((tx>=0) && (ty>=0) && (tx<8) && (ty<8) && (tm[tx][ty]!='#') && (sw[tx][ty][xa1][ya1]>s) && (sw[tx][ty][ya1][ya2]>s))
	{
		y[0]++;
		x[y[0]]=tx;
		y[y[0]]=ty;
	}
}
int main()
{
	long ti,tn,i,de;
	long i1,i2,j1,j2,k1,k2;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		flag=false;
		memset(tm,'#',sizeof(tm));
		memset(sw,1,sizeof(sw));
		for (i=0;i<8;i++)
			scanf("%s",&tm[i]);
		xm=0;ym=0;
		xa1=-1;xa2=-1;ya1=-1;ya2=-1;
		for (i1=0;i1<8;i1++)
			for (i2=0;i2<8;i2++)
				for (j1=0;j1<8;j1++)
					for (j2=0;j2<8;j2++)
					{
						if (tm[i1][i2]=='#') continue;
						if (tm[j1][j2]=='#') continue;
						k1=i1-j1;
						if (k1<0) k1=-k1;
						k2=i2-j2;
						if (k2<0) k2=-k2;
						k1+=k2;
						if (k1==1) sw[i1][i2][j1][j2]=1;
						sw[i1][i2][i1][i2]=0;
						if (tm[i1][i2]=='M') 
						{
							xm=i1;
							ym=i2;
						}
						if ((tm[i1][i2]=='A') && (xa1==-1))
						{
							xa1=i1;
							ya1=i2;
						}
						if ((tm[i1][i2]=='A') && (xa1!=-1))
						{
							xa2=i1;
							ya2=i2;
						}
					}
		for (k1=0;k1<8;k1++)
			for (k2=0;k2<8;k2++)
				for (i1=0;i1<8;i1++)
					for (i2=0;i2<8;i2++)
						for (j1=0;j1<8;j1++)
							for (j2=0;j2<8;j2++)
								sw[i1][i2][j1][j2]=mn(sw[i1][i2][j1][j2],sw[i1][i2][k1][k2]+sw[k1][k2][j1][j2]);
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		x[0]=1;
		x[1]=xm;
		y[1]=ym;
		y[0]=1;
		for (s=1;x[0]<=y[0];s++)
		{
			de=y[0];
			for (i=x[0];i<=de;i++)
			{
				tm[x[i]][y[i]]='#';
				check(x[i]+1,y[i]);
				if (flag) break;
				check(x[i]-1,y[i]);
				if (flag) break;
				check(x[i],y[i]+1);
				if (flag) break;
				check(x[i],y[i]-1);
				if (flag) break;
			}
			if (flag) break;
			x[0]=de+1;
		}
		if (flag) continue;
		if ((sw[xm][ym][xa1][ya1]<100) && (sw[xm][ym][xa2][ya2]<100))
			printf("You are eliminated.\n");
		if ((sw[xm][ym][xa1][ya1]>100) || (sw[xm][ym][xa2][ya2]>100))
			printf("You are trapped in the Matrix.\n");
	}
	return 0;
}

	