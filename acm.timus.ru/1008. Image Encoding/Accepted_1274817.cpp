#include <stdio.h>
#include <memory.h>

bool map[12][12];
char c[100];
long dlx[200];
long dly[200];

int main()
{
	long i,j,n,f,t,x,y,s;
	bool flag;
	i=0;
	scanf("%c",&c[0]);
	while (c[i]>20)
	{
		i++;
		scanf("%c",&c[i]);
	}
	memset(map,false,sizeof(map));
	flag=false;
	for (i=1;i<=20;i++)
		if (c[i]==32)
		{
			flag=true;
			break;
		}
	if (flag)
	{
		s=1;
		f=0;
		for (i=0;i<=20;i++)
			if (c[i]>40)
				f=f*10+c[i]-48;
			else
				break;		
		t=0;
		for (j=i+1;j<=20;j++)
			if (c[j]>40)
				t=t*10+c[j]-48;
			else
				break;
		map[f][t]=true;
		dlx[0]=1;
		dly[0]=1;
		dlx[1]=f;
		dly[1]=t;
		scanf("%s",&c);
		while (c[0]!='.')
		{
			x=dlx[dlx[0]];
			y=dly[dlx[0]];
			for (i=0;i<=20;i++)
				if (c[i]>50)
				{
					dly[0]++;
					if (c[i]=='R')
					{
						dlx[dly[0]]=x+1;
						dly[dly[0]]=y;
						map[dlx[dly[0]]][dly[dly[0]]]=true;
						s++;
					}
					if (c[i]=='T')
					{
						dlx[dly[0]]=x;
						dly[dly[0]]=y+1;
						map[dlx[dly[0]]][dly[dly[0]]]=true;
						s++;
					}
					if (c[i]=='L')
					{
						dlx[dly[0]]=x-1;
						dly[dly[0]]=y;
						map[dlx[dly[0]]][dly[dly[0]]]=true;
						s++;
					}
					if (c[i]=='B')
					{
						dlx[dly[0]]=x;
						dly[dly[0]]=y-1;
						map[dlx[dly[0]]][dly[dly[0]]]=true;
						s++;
					}

				}
				else
					break;
			dlx[0]++;
			scanf("%s",&c);
		}
		printf("%d\n",s);
		for (i=1;i<=10;i++)
			for (j=1;j<=10;j++)
				if (map[i][j])
					printf("%d %d\n",i,j);
		return 0;
	}
	else
	{
		n=0;
		for (i=0;i<=20;i++)
			if (c[i]>40)
				n=n*10+c[i]-48;
			else
				break;
		scanf("%d%d",&f,&t);
		memset(map,false,sizeof(map));
		for (i=2;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			map[x][y]=true;
		}
		printf("%d %d\n",f,t);
		dlx[0]=1;
		dly[0]=1;
		dlx[1]=f;
		dly[1]=t;
		for (;;)
		{
			if (map[dlx[dlx[0]]+1][dly[dlx[0]]])
			{
				map[dlx[dlx[0]]+1][dly[dlx[0]]]=false;
				dly[0]++;
				dlx[dly[0]]=dlx[dlx[0]]+1;
				dly[dly[0]]=dly[dlx[0]];
				printf("R");
			}
			if (map[dlx[dlx[0]]][dly[dlx[0]]+1])
			{
				map[dlx[dlx[0]]][dly[dlx[0]]+1]=false;
				dly[0]++;
				dlx[dly[0]]=dlx[dlx[0]];
				dly[dly[0]]=dly[dlx[0]]+1;
				printf("T");
			}
			if (map[dlx[dlx[0]]-1][dly[dlx[0]]])
			{
				map[dlx[dlx[0]]-1][dly[dlx[0]]]=false;
				dly[0]++;
				dlx[dly[0]]=dlx[dlx[0]]-1;
				dly[dly[0]]=dly[dlx[0]];
				printf("L");
			}
			if (map[dlx[dlx[0]]][dly[dlx[0]]-1])
			{
				map[dlx[dlx[0]]][dly[dlx[0]]-1]=false;
				dly[0]++;
				dlx[dly[0]]=dlx[dlx[0]];
				dly[dly[0]]=dly[dlx[0]]-1;
				printf("B");
			}
			dlx[0]++;
			if (dlx[0]>dly[0])
			{
				printf(".\n");
				return 0;
			}
			else
				printf(",\n");
		}
	}
	return 0;
}







