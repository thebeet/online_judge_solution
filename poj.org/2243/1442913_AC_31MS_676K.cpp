#include <stdio.h>
#include <memory.h>

#define f 5
#define t 12

long map[20][20][20][20];
char inp[10];

long mn(long n1,long n2)
{
	if (n1>n2) return n2;
	else return n1;
}
int main()
{
	long i,j,i1,i2,j1,j2,k1,k2;
	char f1,f2,t1,t2;
	memset(map,50,sizeof(map));
	for (i=f;i<=t;i++)
		for (j=f;j<=t;j++)
		{
			map[i][j][i][j]=0;
			map[i][j][i+1][j+2]=1;
			map[i][j][i-1][j+2]=1;
			map[i][j][i+1][j-2]=1;
			map[i][j][i-1][j-2]=1;
			map[i][j][i+2][j+1]=1;
			map[i][j][i-2][j+1]=1;
			map[i][j][i+2][j-1]=1;
			map[i][j][i-2][j-1]=1;
		}
	for (k1=f;k1<=t;k1++)
		for (k2=f;k2<=t;k2++)
			for (i1=f;i1<=t;i1++)
				for (i2=f;i2<=t;i2++)
					for (j1=f;j1<=t;j1++)
						for (j2=f;j2<=t;j2++)
							map[i1][i2][j1][j2]=mn(map[i1][i2][j1][j2],map[i1][i2][k1][k2]+map[k1][k2][j1][j2]);
	while (scanf("%s",&inp)==1)
	{
		f1=inp[0]-97+f;
		f2=inp[1]-49+f;
		scanf("%s",&inp);
		t1=inp[0]-97+f;
		t2=inp[1]-49+f;
		printf("To get from %c%c to %c%c takes %d knight moves.\n",f1+97-f,f2+49-f,t1+97-f,t2+49-f,map[f1][f2][t1][t2]);
	}
	return 0;
}
