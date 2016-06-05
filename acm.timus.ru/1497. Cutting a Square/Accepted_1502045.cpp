#include <stdio.h>
#include <memory.h>

char map[1100][1100];
bool a,s,d,w;

int main()
{
	long i,j,n,m;
	a=true;s=true;d=true;w=true;
	scanf("%ld",&n);
	memset(map,0,sizeof(map));
	for (i=1;i<=n;i++)
		scanf("%s",map[i]+1);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (map[i][j]=='0')
			{
				if (map[i-1][j]=='1') a=false;
				if (map[i+1][j]=='1') d=false;
				if (map[i][j+1]=='1') s=false;
				if (map[i][j-1]=='1') w=false;
			}
	a=a|d|s|w;
	if (a) printf("Yes\n");
	else printf("No\n");
	return 0;
}


				

		
