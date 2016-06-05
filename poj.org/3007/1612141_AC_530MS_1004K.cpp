#include <stdio.h>
#include <string.h>

char d[10000][100];
char inp[100];
char c1[100];
char c2[100];
char c1t[100];
char c1r[100];
char c2r[100];
char c1tr[100];
long m;

void ad(char c1[100])
{
	long i;
	for (i=1;i<=m;i++)
		if (strcmp(c1,d[i])==0) 
			return;
	m++;
	memcpy(d[m],c1,100);
}

int main()
{
	long ti,tn,i,j,n;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		memset(inp,0,sizeof(inp));
		m=0;
		scanf("%s",&inp);
		memset(d,0,sizeof(d));
		n=strlen(inp);
		for (i=1;i<n;i++)
		{
			memset(c1,0,sizeof(c1));
			memset(c2,0,sizeof(c2));
			memcpy(c1,inp,i);
			memcpy(c2,&inp[i],n-i);
			memcpy(c1r,c1,sizeof(c1));
			memcpy(c2r,c2,sizeof(c2));
			memcpy(c1t,c1,sizeof(c1));
			strrev(c1r);
			strrev(c2r);
			memcpy(c1tr,c1r,sizeof(c1r));

			strcat(c1,c2);
			ad(c1);
			strrev(c1);
			ad(c1);

			strcat(c1r,c2r);
			ad(c1r);
			strrev(c1r);
			ad(c1r);

			strcat(c1t,c2r);
			ad(c1t);
			strrev(c1t);
			ad(c1t);

			strcat(c1tr,c2);
			ad(c1tr);
			strrev(c1tr);
			ad(c1tr);
		}
		printf("%d\n",m);
	}
	return 0;
}
		

