#include <stdio.h>
#include <string.h>

char inp[100];

int main()
{
	long ti,tn,i,s;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		memset(inp,0,sizeof(inp));
		scanf("%s",&inp);
		s=0;
		for (i=0;i<strlen(inp);i++)
			s=(s+inp[i])%3;
		if (s==0)
			printf("Yes.\n");
		else
			printf("No.\n");
	}
	return 0;
}

