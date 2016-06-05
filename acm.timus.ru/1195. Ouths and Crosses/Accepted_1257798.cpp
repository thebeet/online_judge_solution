#include <stdio.h>
char map[10];
long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

long mn(long a,long b)
{
	if (a<b) return a;
	else return b;
}

long check(char mm[10])
{
	if ((mm[0]==88) && (mm[1]==88) && (mm[2]==88))
		return 1;
	if ((mm[3]==88) && (mm[4]==88) && (mm[5]==88))
		return 1;
	if ((mm[6]==88) && (mm[7]==88) && (mm[8]==88))
		return 1;
	if ((mm[0]==88) && (mm[3]==88) && (mm[6]==88))
		return 1;
	if ((mm[1]==88) && (mm[4]==88) && (mm[7]==88))
		return 1;
	if ((mm[2]==88) && (mm[5]==88) && (mm[8]==88))
		return 1;
	if ((mm[0]==88) && (mm[4]==88) && (mm[8]==88))
		return 1;
	if ((mm[6]==88) && (mm[4]==88) && (mm[2]==88))
		return 1;
	if ((mm[0]==79) && (mm[1]==79) && (mm[2]==79))
		return -1;
	if ((mm[3]==79) && (mm[4]==79) && (mm[5]==79))
		return -1;
	if ((mm[6]==79) && (mm[7]==79) && (mm[8]==79))
		return -1;
	if ((mm[0]==79) && (mm[3]==79) && (mm[6]==79))
		return -1;
	if ((mm[1]==79) && (mm[4]==79) && (mm[7]==79))
		return -1;
	if ((mm[2]==79) && (mm[5]==79) && (mm[8]==79))
		return -1;
	if ((mm[0]==79) && (mm[4]==79) && (mm[8]==79))
		return -1;
	if ((mm[6]==79) && (mm[4]==79) && (mm[2]==79))
		return -1;
	return 0;
}

long st(char map[10],char g)
{
	long i,s;
	bool f=false;
	s=check(map);
	if (s!=0) return s;
	if (g==88) s=-1;
	else s=1;
	for (i=0;i<=8;i++)
	{
		if (map[i]==35)
		{
			map[i]=g;
			if (g==88) s=mx(s,st(map,79));
			else s=mn(s,st(map,88));
			map[i]=35;
			f=true;
		}
	}
	if (f) return s;
	else return 0;
}

long main()
{
	long i,n,p;
	p=0;
	for (i=0;i<=8;i++)
	{
		scanf("%c",&map[i]);
		while (map[i]<30) 
			scanf("%c",&map[i]);
		if (map[i]==88) p++;
		if (map[i]==79) p--;
	}
	if (p==1) n=st(map,79);
	else n=st(map,88);
	if (n==1) printf("Crosses win\n");
	if (n==0) printf("Draw\n");
	if (n==-1) printf("Ouths win\n");
	return 0;
}

