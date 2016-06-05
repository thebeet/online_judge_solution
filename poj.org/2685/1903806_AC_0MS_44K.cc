#include <stdio.h>
#include <string.h>

char inp[100];


int main()
{
	long ti,tn,n,p,m,s,s1,s2;
	scanf("%ld",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		memset(inp,0,sizeof(inp));
		scanf("%s",&inp);
		n=strlen(inp)-1;
		p=0;
		s=0;
		while (p<=n)
		{
			m=1;
			if (inp[p]<'a')
			{
				m=inp[p]-48;
				p++;
			}
			if (inp[p]=='m') s+=(1000*m);
			if (inp[p]=='c') s+=(100*m);
			if (inp[p]=='x') s+=(10*m);
			if (inp[p]=='i') s+=(1*m);
			p++;
		}
		s1=s;
		memset(inp,0,sizeof(inp));
		scanf("%s",&inp);
		n=strlen(inp)-1;
		p=0;
		s=0;
		while (p<=n)
		{
			m=1;
			if (inp[p]<'a')
			{
				m=inp[p]-48;
				p++;
			}
			if (inp[p]=='m') s+=(1000*m);
			if (inp[p]=='c') s+=(100*m);
			if (inp[p]=='x') s+=(10*m);
			if (inp[p]=='i') s+=(1*m);
			p++;
		}
		s2=s;
		s1+=s2;
		s2=s1/1000;
		if (s2>1) printf("%ld",s2);
		if (s2>0) printf("m");
		s1%=1000;
		s2=s1/100;
		if (s2>1) printf("%ld",s2);
		if (s2>0) printf("c");
		s1%=100;
		s2=s1/10;
		if (s2>1) printf("%ld",s2);
		if (s2>0) printf("x");
		s1%=10;
		s2=s1;
		if (s2>1) printf("%ld",s2);
		if (s2>0) printf("i");
		printf("\n");
	}
	return 0;
}
