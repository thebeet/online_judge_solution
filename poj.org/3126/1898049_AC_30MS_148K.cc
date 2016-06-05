#include <stdio.h>
#include <memory.h>

bool ss[11000];
bool ssbak[11000];
long dl[10000];
long sss[11000];

int main()
{
	long ti,tn,f,t,i,j,p,d;
	scanf("%ld",&tn);
	memset(ss,true,sizeof(ss));
	for (i=2;i<=150;i++)
		if (ss[i])
		{
			j=i*i;
			while (j<10200)
			{
				ss[j]=false;
				j+=i;
			}
		}
	for (i=1;i<=999;i++)
		ss[i]=false;
	memcpy(&ssbak,ss,sizeof(ss));
	for (ti=1;ti<=tn;ti++)
	{
		memcpy(&ss,ssbak,sizeof(ss));
		memset(dl,0,sizeof(dl));
		memset(sss,0,sizeof(sss));
		scanf("%ld%ld",&f,&t);
		dl[0]=1;
		dl[1]=f;
		d=1;
		sss[f]=0;
		ss[f]=false;
		while (ss[t])
		{
			p=dl[d];
			p=(p/10)*10;
			for (i=0;i<=9;i++)
				if (ss[p+i])
				{
					ss[p+i]=false;
					sss[p+i]=sss[dl[d]]+1;
					dl[0]++;
					dl[dl[0]]=p+i;
				}
			p=dl[d];
			p=(p/100)*100+p%10;
			for (i=0;i<=90;i+=10)
				if (ss[p+i])
				{
					ss[p+i]=false;
					sss[p+i]=sss[dl[d]]+1;
					dl[0]++;
					dl[dl[0]]=p+i;
				}
			p=dl[d];
			p=(p/1000)*1000+p%100;
			for (i=0;i<=900;i+=100)
				if (ss[p+i])
				{
					ss[p+i]=false;
					sss[p+i]=sss[dl[d]]+1;
					dl[0]++;
					dl[dl[0]]=p+i;
				}
			p=dl[d];
			p=p%1000;
			for (i=1000;i<=9000;i+=1000)
				if (ss[p+i])
				{
					ss[p+i]=false;
					sss[p+i]=sss[dl[d]]+1;
					dl[0]++;
					dl[dl[0]]=p+i;
				}
			d++;
		}
		printf("%ld\n",sss[t]);
	}
	return 0;
}			
