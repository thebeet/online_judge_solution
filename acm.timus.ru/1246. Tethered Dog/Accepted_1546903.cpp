#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAXN 200010

struct point
{
	double x,y;
	long id;
};

point p[MAXN];
point p2[MAXN];
long n;
long st[MAXN];
bool us[MAXN];

bool compare(point p1,point p2)
{
	if ((p1.x<p2.x) || ((p1.x==p2.x) && (p1.y<p2.y)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

double xj(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

void tubao()
{
	long i;
	double ret;
	bool flag;
	sort(p+1,p+n+1,compare);
	memset(us,true,sizeof(us));
	i=3;
	st[0]=2;
	st[1]=1;
	st[2]=2;
	flag=false;
	while (i<=n)
	{
		ret=xj(p[st[st[0]-1]],p[st[st[0]]],p[i]);
		if (ret<0)
		{
			st[0]++;
			st[st[0]]=i;
			i++;
			flag=true;
		}
		else
		{
			if (ret==0)
			{
				st[0]++;
				st[st[0]]=i;
				i++;
			}
			else
				st[0]--;
		}
	}
	for (i=1;i<=st[0];i++)
		us[st[i]]=false;
	us[1]=true;
	i=n-1;
	while (i>=1)
	{
		if (!us[i]) 
		{
			i--;
			continue;
		}
		ret=xj(p[st[st[0]-1]],p[st[st[0]]],p[i]);
		if (ret<0)
		{
			st[0]++;
			st[st[0]]=i;
			i--;
			flag=true;
		}
		else
		{
			if (ret==0)
			{
				st[0]++;
				st[st[0]]=i;
				i--;
			}
			else
				st[0]--;
		}
	}
	for (i=1;i<st[0];i++)
		p2[i]=p[st[i]];
	n=st[0]-1;
}

int main() 
{
	long i;
	scanf("%d",&n);
	memset(p,0,sizeof(p));
	for (i=1;i<=n;i++)
	{
		scanf("%lf%lf",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	tubao();
	memcpy(p,p2,sizeof(p));
	p[n+1].id=p[1].id;
	if (((p[1].id<p[2].id) && (p[2].id<p[3].id)) || ((p[1].id>p[2].id) && (p[2].id<p[3].id) && (p[3].id<p[4].id)) || ((p[1].id<p[2].id) && (p[2].id>p[3].id) && (p[3].id<p[4].id)))
	{
		printf("cw\n");
	}
	else
	{
		printf("ccw\n");
	}
	return 0;
}
