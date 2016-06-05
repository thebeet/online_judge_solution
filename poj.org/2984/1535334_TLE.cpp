#include <stdio.h>
#include <memory.h>

#define r 1000000

char f[10110];
long h[50010];
long s[50010];
long hp[20010];
long n;

void mm()
{
	long i;
	for (i=h[0];i>0;i--)
		h[i+2]+=h[i];
	h[0]+=2;
	for (i=1;i<=h[0];i++)
	{
		h[i+1]=h[i+1]+h[i]/2;
		h[i]%=2;
	}
	while (h[h[0]+1]>0)
		h[0]++;
}
	
void mu2()
{
	long i;
	for (i=1;i<=hp[0];i++)
		hp[i]*=2;
	for (i=1;i<=hp[0];i++)
		if (hp[i]>r-1)
		{
			hp[i+1]=hp[i+1]+hp[i]/r;
			hp[i]%=r;
		}
	while (hp[hp[0]+1]>0)
		hp[0]++;
}

int main()
{
	long i,j,k,t;
	n=1;
	memset(f,0,sizeof(f));
	memset(hp,0,sizeof(hp));
	memset(h,0,sizeof(h));
	memset(s,0,sizeof(s));
	scanf("%c",&f[n]);
	while (f[n]>30)
	{
		f[n]-=48;
		n++;
		scanf("%c",&f[n]);
	}
	n--;
	h[0]=1;
	h[1]=1;
	s[1]=f[n];
	for (i=2;i<=n;i++)
	{
		t=f[n-i+1];
		mm();
		for (j=1;j<=h[0];j++)
			s[j+i-1]=s[j+i-1]+h[j]*t;
	}
	k=0;
	for (i=1;i<=50000;i++)
	{
		s[i+1]=s[i+1]+s[i]/2;
		s[i]%=2;
		if (s[i]==1) k++;
	}
	hp[0]=1;
	hp[1]=1;
	for (i=1;i<=k;i++)
		mu2();
	hp[1]--;
	printf("%d",hp[hp[0]]);
	for (i=hp[0]-1;i>=1;i--)
	{
		if (hp[i]<100000) printf("0");
		if (hp[i]<10000) printf("0");
		if (hp[i]<1000) printf("0");
		if (hp[i]<100) printf("0");
		if (hp[i]<10) printf("0");
		printf("%d",hp[i]);
	}
	printf("\n");
	return 0;
}
