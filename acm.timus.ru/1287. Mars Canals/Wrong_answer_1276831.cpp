#include <stdio.h>

char map[1500][1500];
long m[5];

int main()
{
	long i,j,n,l,st;
	char c;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%c",&c);
		scanf("%c",&map[i][1]);
		if (map[i][1]=='S') st=1;
		else st=2;
		l=1;
		for (j=2;j<=n;j++)
		{
			scanf("%c",&map[i][j]);
			if ((st==1) && (map[i][j]=='S')) 
			{
				l++;
				continue;
			}
			if ((st==2) && (map[i][j]=='s')) 
			{
				l++;
				continue;
			}
			if ((st==1) && (map[i][j]=='s')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=2;
				continue;
			}
			if ((st==2) && (map[i][j]=='S')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=1;
				continue;
			}
		}
		if (m[st]<l) m[st]=l;
	}
	for (j=1;j<=n;j++)
	{
		if (map[1][j]=='S') st=1;
		else st=2;
		l=1;
		for (i=2;i<=n;i++)
		{
			if ((st==1) && (map[i][j]=='S')) 
			{
				l++;
				continue;
			}
			if ((st==2) && (map[i][j]=='s')) 
			{
				l++;
				continue;
			}
			if ((st==1) && (map[i][j]=='s')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=2;
				continue;
			}
			if ((st==2) && (map[i][j]=='S')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=1;
				continue;
			}
		}
		if (m[st]<l) m[st]=l;
	}
	for (j=1;j<=n;j++)
	{
		if (map[1][j]=='S') st=1;
		else st=2;
		l=1;
		for (i=2;i<=n-j+1;i++)
		{
			if ((st==1) && (map[i][j+i-1]=='S')) 
			{
				l++;
				continue;
			}
			if ((st==2) && (map[i][j+i-1]=='s')) 
			{
				l++;
				continue;
			}
			if ((st==1) && (map[i][j+i-1]=='s')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=2;
				continue;
			}
			if ((st==2) && (map[i][j+i-1]=='S')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=1;
				continue;
			}
		}
		if (m[st]<l) m[st]=l;
	}
	for (j=1;j<=n;j++)
	{
		if (map[j][1]=='S') st=1;
		else st=2;
		l=1;
		for (i=2;i<=n-j+1;i++)
		{
			if ((st==1) && (map[j+i-1][i]=='S')) 
			{
				l++;
				continue;
			}
			if ((st==2) && (map[j+i-1][i]=='s')) 
			{
				l++;
				continue;
			}
			if ((st==1) && (map[j+i-1][i]=='s')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=2;
				continue;
			}
			if ((st==2) && (map[j+i-1][i]=='S')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=1;
				continue;
			}
		}
		if (m[st]<l) m[st]=l;
	}
	for (j=1;j<=n;j++)
	{
		if (map[1][j]=='S') st=1;
		else st=2;
		l=1;
		for (i=2;i<=j;i++)
		{
			if ((st==1) && (map[i][j-i+1]=='S')) 
			{
				l++;
				continue;
			}
			if ((st==2) && (map[i][j-i+1]=='s')) 
			{
				l++;
				continue;
			}
			if ((st==1) && (map[i][j-i+1]=='s')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=2;
				continue;
			}
			if ((st==2) && (map[i][j-i+1]=='S')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=1;
				continue;
			}
		}
		if (m[st]<l) m[st]=l;
	}
	for (j=1;j<=n;j++)
	{
		if (map[n][j]=='S') st=1;
		else st=2;
		l=1;
		for (i=2;i<=j;i++)
		{
			if ((st==1) && (map[n-i+1][j-i+1]=='S')) 
			{
				l++;
				continue;
			}
			if ((st==2) && (map[n-i+1][j-i+1]=='s')) 
			{
				l++;
				continue;
			}
			if ((st==1) && (map[n-i+1][j-i+1]=='s')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=2;
				continue;
			}
			if ((st==2) && (map[n-i+1][j-i+1]=='S')) 
			{
				if (m[st]<l) m[st]=l;
				l=1;
				st=1;
				continue;
			}
		}
		if (m[st]<l) m[st]=l;
	}
	if (m[1]>m[2]) 
	{
		printf("S\n");
		printf("%d\n",m[1]);
	}
	else
	{
		if (m[2]>m[1]) 
		{
			printf("s\n");
			printf("%d\n",m[2]);
		}
		else
		{
			printf("?\n");
			printf("%d\n",m[2]);
		}
	}
	return 0;
}







