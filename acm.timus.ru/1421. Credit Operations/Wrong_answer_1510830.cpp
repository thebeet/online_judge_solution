#include <stdio.h>
#include <memory.h>

long sr[110],sc[110],ans[110][110];
long id[110];
long n;

int main()
{
	long i,j,f,t,d,tmp;
	bool aans;
	scanf("%ld",&n);
	aans=true;
	memset(sr,0,sizeof(sr));
	memset(sc,0,sizeof(sc));
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&sr[i]);
		if (sr[i]>n*100) aans=false;
		sr[0]+=sr[i];
	}
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&sc[i]);
		if (sc[i]>n*100) aans=false;
		sc[0]+=sc[i];
	}
	if (sc[0]!=sr[0]) aans=false;
	if (aans)
	{
		for (i=1;i<=n;i++)
		{
			id[i]=i;
		}
		id[n+1]=105;
		for (i=2;i<=n;i++)
		{
			for (j=1;j<i;j++)
			{
				if (sc[id[i]]>sc[id[j]])
				{
					tmp=id[i];
					id[i]=id[j];
					id[j]=tmp;
				}
			}
		}
		memset(ans,0,sizeof(ans));
		for (i=1;i<=n;i++)
		{
			f=1;
			t=0;
			while (sr[i]>0)
			{
				t++;
				if (t>n) 
				{
					aans=false;
					break;
				}
				d=sc[id[t]]-sc[id[t+1]];
				while (d*(t-f+1)<sr[i])
				{
					if (t>n) 
					{
						aans=false;
						break;
					}
					while ((ans[i][id[f]]+d>=100) && (f<=t))
					{
						sr[i]-=(100-ans[i][id[f]]);
						sc[id[f]]-=(100-ans[i][id[f]]);
						ans[i][id[f]]=100;
						f++;
					}
					for (j=f;j<=t;j++)
					{
						ans[i][id[j]]+=d;
						sc[id[j]]-=d;
						sr[i]-=d;
					}
					t++;
					d=sc[id[t]]-sc[id[t+1]];
				}
				if (sr[i]==0) break;
				if (t>n) 
				{
					aans=false;
					break;
				}
				if (aans==false) break;
				d=sr[i]/(t-f+1);
				while ((ans[i][id[f]]+d>=100) && (f<=t))
				{
					sr[i]-=(100-ans[i][id[f]]);
					sc[id[f]]-=(100-ans[i][id[f]]);
					ans[i][id[f]]=100;
					f++;
				}
				for (j=f;j<=t;j++)
				{
					ans[i][id[j]]+=d;
					sc[id[j]]-=d;
					sr[i]-=d;
				}
				for (j=t;(sr[i]>0)&&(j>=f);j--)
				{
					ans[i][id[j]]++;
					sc[id[j]]--;
					sr[i]--;
				}
			}
			if (aans==false) break;
		}
		if (aans)
		{
			printf("YES\n");
			for (i=1;i<=n;i++)
			{
				for (j=1;j<n;j++)
				{
					printf("%ld ",ans[i][j]);
				}
				printf("%ld\n",ans[i][j]);
			}
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
