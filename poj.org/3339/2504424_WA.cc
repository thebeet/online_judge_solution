#include <stdio.h>
#include <algorithm>

using namespace std;

struct people
{
	char name[128];
	char type[16];
	int id;
	int years;
}ps[128];

int ans[16];

int mm[8];

int getpeople(people &p1)
{
	char ch;
	scanf("%d", &p1.id);
	if (p1.id == 0)
	{
		return EOF;
	}
	scanf("%s%s", p1.name, p1.type);
	while (scanf("%c", &ch), ch == ' ')
	{
		int yst, yed;
		scanf("%d-%d", &yst, &yed);
		p1.years += (yed - yst + 1);
	}
	return 1;
}

void outpeople(people &p1, int noid, char tp)
{
	if ((p1.id != noid) && ((p1.type[0] == tp) || (tp == ' ')))
	{
		printf("%d %s %c\n", p1.id, p1.name, p1.type[0]);
	}
}

bool cmp(people p1, people p2)
{
	return (p1.id < p2.id);
}

char seq[8] = { 'G', 'D', 'M', 'S' };

int main()
{
	int n;
	memset(ps, 0, sizeof(ps));
	while (getpeople(ps[1]) != EOF)
	{
		int i, k, mx, mxp;
		n = 22;
		memset(mm, 0, sizeof(mm));
		mm[0] = 1;
		mx = 0;
		
		for (i = 2; i <= 22; ++i)
		{
			getpeople(ps[i]);
		}
		
		scanf("%d-%d-%d", &mm[1], &mm[2], &mm[3]);
		
		memset(ans, 0, sizeof(ans));
		
		sort(ps + 1, ps + n + 1, cmp);
		
		for (k = 0; k < 4; ++k)
		{
			if (mm[k] > 0)
			{
				for (i = 1; i <= n; ++i)
				{
					if (ps[i].type[0] == seq[k])
					{
						--mm[k];
						ans[++ans[0]] = i;
						if (ps[i].years >= mx)
						{
							mx = ps[i].years;
							mxp = i;
						}
						if (mm[k] == 0)
						{
							break;
						}
					}
				}
				if (i > n)
				{
					break;
				}
			}
		}
		if (k < 4)
		{
			printf("IMPOSSIBLE TO ARRANGE\n");
		}
		else
		{
			outpeople(ps[mxp], 0, ' ');
			for (k = 0; k < 4; ++k)
			{
				for (i = 1; i <= 11; ++i)
				{
					outpeople(ps[ans[i]], mxp, seq[k]);
				}
			}
		}
		printf("\n");
		memset(ps, 0, sizeof(ps));
	}
	return 0;
}
