#include <stdio.h>
#include <memory.h>

long s[1010];;

int main()
{
	long a,b,c,d,e,f,g,h,i,j,ti,tn;
	scanf("%ld",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld",&a,&b,&c,&d,&e,&f,&g,&h,&i);
		memset(s,0,sizeof(s));
		s[0]=a;
		s[1]=b;
		s[2]=c;
		for (j=3;j<=i;j++)
		{
			s[j]=((d*s[j-1]+e*s[j-2]-f*s[j-3])%g+g)%g;
			j++;
			s[j]=((f*s[j-1]-d*s[j-2]+e*s[j-3])%h+h)%h;
		}
		printf("%ld\n",s[i]);
	}
	return 0;
}
