#include <stdio.h>
#include <memory.h>

__int64 f1[50],f2[50];

__int64 c(__int64 a,__int64 b)
{
	__int64 i,s;
	if (a>b) return 0;
	if (a>b/2) a=b-a;
	s=1;
	for (i=1;i<=a;i++)
		s=s*(b+1-i)/i;
	return s;
}

__int64 calc(__int64 f[50],__int64 k)
{
	__int64 i,n,s;
	n=f[0];
	s=0;
	for (i=f[0];i>=1;i--)
	{
		if (f[i]<=1)
			n--;
		if (f[i]==1)
		{
			s+=c(k,n);
			if (k==0) break;
			k--;
		}
		if (f[i]>1)
		{
			s+=c(k,n);
			break;
		}
	}
	return s;
}

	
		

int main()
{
	long in1,in2,in3,in4;
	__int64 x,y,k,b;
	scanf("%d%d%d%d",&in1,&in2,&in3,&in4);
	x=in1;y=in2;k=in3;b=in4;
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	y++;
	while (x>0)
	{
		f1[0]++;
		f1[f1[0]]=x%b;
		x/=b;
	}
	while (y>0)
	{
		f2[0]++;
		f2[f2[0]]=y%b;
		y/=b;
	}
	printf("%d\n",calc(f2,k)-calc(f1,k));
	return 0;
}
