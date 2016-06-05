#include <stdio.h>
#include <memory.h>

#define r 100
#define w 2
#define sizeL 400

char inp[1000];
long hp[10][100];

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

void tzup(long hp1[])
{
	long i;
	for (i=1;i<=hp1[0];i++)
	{
		hp1[i+1]+=(hp1[i]/r);
		hp1[i]%=r;
	}
	while (hp1[hp1[0]+1]>0)
	{
		hp1[0]++;
		hp1[hp1[0]+1]+=(hp1[hp1[0]]/r);
		hp1[hp1[0]]%=r;
	}
}

void tzdown(long hp1[])
{
	long i;
	for (i=1;i<=hp1[0];i++)
	{
		hp1[i+1]+=((hp1[i]-999)/r);
		hp1[i]=(hp1[i]%r+r)%r;
	}
	while ((hp1[hp1[0]]==0) && (hp1[0]>1))
		hp1[0]--;
}

void hp_eq_hp(long hp1[],long hp2[])
{
	memcpy(hp1,hp2,sizeL);
}

void hp_eq_num(long hp1[],long n1)
{
	memset(hp1,0,sizeL);
	hp1[0]=1;
	hp1[1]=n1;
	tzup(hp1);
}

long hp_iseq_hp(long hp1[],long hp2[])
{
	long i,l;
	if (hp1[0]>hp2[0]) return 1;
	if (hp2[0]>hp1[0]) return -1;
	l=hp1[0];
	for (i=l;i>=1;i--)
	{
		if (hp1[i]>hp2[i]) return 1;
		if (hp2[i]>hp1[i]) return -1;
	}
	return 0;
}

void hp_inp(long hp1[])
{
	long i,j,k,l,t;
	memset(hp1,0,sizeL);
	memset(inp,0,sizeof(inp));
	scanf("%s",inp);
	l=strlen(inp);
	k=0;
	for (i=l-1;i>=0;i-=w)
	{
		if (inp[i]==0) break;
		k++;
		t=i-w+1;
		if (t<0) t=0;
		for (j=t;j<=i;j++)
		{
			if (inp[i]>0)
				hp1[k]=hp1[k]*10+inp[j]-48;
		}
	}
	hp1[0]=k;
}

void hp_add_hp(long hp1[],long hp2[],long hp3[])
{
	long i,l;
	memset(hp3,0,sizeL);
	l=mx(hp1[0],hp2[0]);
	for (i=1;i<=l;i++)
		hp3[i]=hp1[i]+hp2[i];
	hp3[0]=l;
	tzup(hp3);
}

void hp_dec_hp(long hp1[],long hp2[],long hp3[])
{
	long i,l;
	memset(hp3,0,sizeL);
	l=hp1[0];
	for (i=1;i<=l;i++)
		hp3[i]=hp1[i]-hp2[i];
	hp3[0]=hp1[0];
	tzdown(hp3);
}

void hp_mul_num(long hp1[],long n1,long hp2[])
{
	long i,l;
	memset(hp2,0,sizeL);
	l=hp1[0];
	for (i=1;i<=l;i++)
		hp2[i]=hp1[i]*n1;
	hp2[0]=l;
	tzup(hp2);
}

void hp_mul_hp(long hp1[],long hp2[],long hp3[])
{
	long i,j;
	memset(hp3,0,sizeL);
	for (i=1;i<=hp1[0];i++)
		for (j=1;j<=hp2[0];j++)
			hp3[i+j-1]+=(hp1[i]*hp2[j]);
	hp3[0]=hp1[0]+hp2[0]-1;
	tzup(hp3);
}

long hp_div_num(long hp1[],long n1,long hp2[])
{
	long i,l,m;
	memset(hp2,0,sizeL);
	l=hp1[0];
	for (i=l;i>=1;i--)
	{
		hp1[i-1]+=r*(hp1[i]%n1);
		hp2[i]/=n1;
	}
	m=hp1[0]/r;
	hp1[0]=l;
	while ((hp1[hp1[0]]==0) && (hp1[0]>1))
		hp1[0]--;
	return m;
}

void hp_div_hp(long hp1[],long hp2[],long hp3[],long hp4[],long hp5[])
{
	long l,ret;
	memset(hp3,0,sizeL);
	l=hp1[0]-hp2[0]+1;
	hp3[0]=l;
	while (l>0)
	{
		hp3[l]=1;
		ret=1;
		while (ret==1)
		{
			memset(hp5,0,sizeL);
			hp_mul_hp(hp3,hp2,hp5);
			ret=hp_iseq_hp(hp1,hp5);
			if (ret==-1)
			{
				hp3[l]--;
				l--;
			}
			if (ret==0)
			{
				l=0;
			}
			if (ret==1)
			{
				hp3[l]++;
			}
		}
	}
	while ((hp3[hp3[0]]==0) && (hp3[0]>1))
		hp3[0]--;
	if (ret==0)
	{
		memset(hp4,0,sizeL);
		hp4[0]=1;
		return;
	}
	hp_dec_hp(hp5,hp2,hp5);
	memset(hp4,0,sizeL);
	hp_dec_hp(hp1,hp5,hp4);
}

void hp_sqrt(long hp1[],long hp2[],long hp3[])
{
	long l,ret;
	memset(hp2,0,sizeL);
	l=hp1[0]/2+1;
	hp2[0]=l;
	while (l>0)
	{
		hp2[l]=1;
		ret=1;
		while (ret==1)
		{
			memset(hp3,0,sizeL);
			hp_mul_hp(hp2,hp2,hp3);
			ret=hp_iseq_hp(hp1,hp3);
			if (ret==-1)
			{
				hp2[l]--;
				l--;
			}
			if (ret==0)
			{
				l=0;
			}
			if (ret==1)
			{
				hp2[l]++;
			}
		}
	}
	while ((hp3[hp3[0]]==0) && (hp3[0]>1))
		hp3[0]--;
}
/*
void hp_gcd_hp(long hp1[],long hp2[],long hp3[],long hp4[],long hp5[],long hp6[])
{
	long t;
	if (hp_iseq_hp(hp1,hp2)<0)
	{
		t=p1;
		p1=p2;
		p2=t;
	}
	while ((hp2[0]>1) || (hp2[1]!=0))
	{
		hp_div_hp(hp1,hp2,hp4,hp5,hp6);
		hp_eq_hp(hp1,hp2);
		hp_eq_hp(hp2,hp5);
	}
	hp_eq_hp(p3,p1);
}
*/
void hp_out(long hp1[])
{
	long i;
	printf("%ld",hp1[hp1[0]]);
	for (i=hp1[0]-1;i>=1;i--)
	{
//		if (hp1[i]<100) printf("0");
		if (hp1[i]<10) printf("0");
		printf("%ld",hp1[i]);
	}
	printf("\n");
}

int main()
{
	long i,n,m;
	memset(hp,0,sizeof(hp));
	scanf("%ld%ld",&n,&m);
	while (n>0)
	{
		hp_eq_num(hp[1],1);
		hp_eq_num(hp[2],n);
		for (i=1;i<=m;i++)
		{
			hp_mul_hp(hp[1],hp[2],hp[3]);
			hp_eq_hp(hp[1],hp[3]);
		}
		hp_out(hp[1]);
		scanf("%ld%ld",&n,&m);
	}
	return 0;
}
