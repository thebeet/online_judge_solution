#include <stdio.h>
#include <string.h>

#define MAXN 10010

char str[MAXN][30];
long id[MAXN];
char inp[30];

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
			id[n]=n;
			j=n;
			while ((j>1) && (strcmp(str[id[j]],str[id[j-1]])<0))
			{
				tmp=id[j];
				id[j]=id[j-1];
				id[j-1]=tmp;
				j--;
			}
			if ((j>1) && (strcmp(str[id[j]],str[id[j-1]])==0))
			{
				for (;j<n;j++)
				{
					id[j]=id[j+1];
				}
				n--;
			}
		}
		else
		{
			memcpy(inp,inp+1,sizeof(inp)-1);
			printf("%s\n",inp);
			m=0;
			for (i=1;((i<=n) && (m<20));i++)
			{
				if (strcompare(inp,str[id[i]],strlen(inp)))
				{
					m++;
					printf("  %s\n",str[id[i]]);
				}
			}
		}
		memset(inp,0,sizeof(inp));
	}
	return 0;
}
				