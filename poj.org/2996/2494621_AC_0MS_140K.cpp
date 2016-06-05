#include <stdio.h>
#include <algorithm>

using namespace std;

char inp[256];
char seq[10] = { 'K', 'Q', 'R', 'B', 'N', 'P' };

struct pos
{
	char c;
	int l;
};

struct chess
{
	int size;
	pos poss[16];
}cs[256];

bool cmp(pos p1, pos p2)
{
	if (p1.l == p2.l)
	{
		return (p1.c < p2.c);
	}
	else
	{
		return (p1.l < p2.l);
	}
}

int main()
{
	int i, j, k, pp;
	for (i = 8; i >= 1; --i)
	{
		char ch;
		scanf("%*s%s", inp);
		for (j = 2, ch = 'a'; ch <= 'h'; j += 4, ++ch)
		{
			cs[(int)inp[j]].poss[++cs[(int)inp[j]].size].c = ch;
			cs[(int)inp[j]].poss[cs[(int)inp[j]].size].l = i;
		}
	}
	k = 0;
	printf("White: ");
	for (pp = 0; pp < 6; ++pp)
	{
		int i = seq[pp];
		if (cs[i].size > 0)
		{
			sort(cs[i].poss + 1,cs[i].poss + cs[i].size + 1, cmp);
			for (j = 1; j <= cs[i].size; ++j)
			{
				++k;
				if (k > 1)
				{
					printf(",");
				}
				if (i != 'P')
				{
					printf("%c", (char)i);
				}
				printf("%c%d", cs[i].poss[j].c, cs[i].poss[j].l);
			}
		}
	}
	printf("\n");
	k = 0;
	printf("Black: ");
	for (pp = 0; pp < 6; ++pp)
	{
		int i = seq[pp] - 'A' + 'a';
		if (cs[i].size > 0)
		{
			//sort(cs[i].poss + 1,cs[i].poss + cs[i].size + 1, cmp);
			for (j = 1; j <= cs[i].size; ++j)
			{
				++k;
				if (k > 1)
				{
					printf(",");
				}
				if (i != 'p')
				{
					printf("%c", (char)(i + 'A' - 'a'));
				}
				printf("%c%d", cs[i].poss[j].c, cs[i].poss[j].l);
			}
		}
	}
	printf("\n");
	return 0;
}
