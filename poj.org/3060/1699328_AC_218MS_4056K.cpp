#include <stdio.h>
#include <memory.h>

#define m 1000000001

long td[1010][1010];
long tdx[1010];
long tdy[1010];

int main()
{
	long ti,tn,i,j,n,d,x,y,px,py;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d",&d,&n);
		memset(td,0,sizeof(td));
		memset(tdx,0,sizeof(tdx));
		memset(tdy,0,sizeof(tdy));
		px=0;py=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			td[(x+m)%d][(y+m)%d]++;
			tdx[(x+m)%d]++;
			tdy[(y+m)%d]++;
		}
		for (i=0;i<d;i++)
			for (j=0;j<d;j++)
				if (tdx[i]+tdy[j]-td[i][j]<tdx[px]+tdy[py]-td[px][py])
				{
					px=i;
					py=j;
				}
		printf("%d\n",tdx[px]+tdy[py]-td[px][py]);
	}
	return 0;
}



