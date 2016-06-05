#include <stdio.h>
#include <string.h>

#define MAXN 10010

char str[MAXN][30];
char inp[30];
long ans[MAXN];

bool strcompare(char str1[30],char str2[30],long l)
{
	long i;
	for (i=0;i<l;i++)
	{
		if (str1[i]!=str2[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	long i,j,n,m,l,tmp;
	n=1;
	memset(str,0,sizeof(str));
	memcpy(str[1],"sun",sizeof("sun"));
	memset(inp,0,sizeof(inp));
	while (scanf("%s",inp)!=EOF)
	{
		if (inp[0]=='+')
		{
			n++;
			memcpy(str[n],inp+1,sizeof(inp)-1);
		}
		else
		{
			memcpy(inp,inp+1,sizeof(inp)-1);
			printf("%s\n",inp);
			memset(ans,0,sizeof(ans));
			for (i=1;i<=n;i++)
			{
				if (strcompare(inp,str[i],strlen(inp)))
				{
					ans[0]++;
					j=ans[0];
					ans[j]=i;
					while ((j>1) && (strcmp(str[ans[j]],str[ans[j-1]])<0))
					{
						tmp=ans[j];
						ans[j]=ans[j-1];
						ans[j-1]=tmp;
						j--;
					}
					if ((j>1) && (strcmp(str[ans[j]],str[ans[j-1]])==0))
					{
						for (;j<ans[0];j++)
						{
							ans[j]=ans[j+1];
						}
						ans[0]--;
					}
					if (ans[0]>20) ans[0]=20;
				}
			}
			for (i=1;i<=ans[0];i++)
			{
				printf("  %s\n",str[ans[i]]);
			}
		}
		memset(inp,0,sizeof(inp));
	}
	return 0;
}
				