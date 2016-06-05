#include <stdio.h>
#include <string.h>

const int MAXN = 6000010;

int father[MAXN];
short rank[MAXN];
int stack[500010];
int argv[16];
int n;
int k;

void set_init()
{
	memset(father, 0, (n + 1) * sizeof(int));
	memset(rank, 0, (n + 1) * sizeof(short));
}

int find(int a)
{
	int pp = a;
	stack[0] = 0;
	while (father[pp] != 0)
	{
		stack[++stack[0]] = pp;
		pp = father[pp];
	}
	while (stack[0] > 1)
	{
		father[stack[--stack[0]]] = pp;
	}
	return pp;
}

void set_connect(int a, int b)
{
	int fa = find(a);
	int fb = find(b);
	if (rank[fa] < rank[fb])
	{
		father[fa] = fb;
	}
	else
	{
		father[fb] = fa;
		 if (rank[fa] == rank[fb])
		 {
			 ++rank[fa];
		 }
	}
}

inline bool set_isconnect(int a, int b)
{
	return (find(a) == find(b));
}

void getlinenum(void)
{
	char buf[128];
	gets(buf);
	argv[3] = 1;
	argv[4] = 1;
	argv[5] = 0;
	sscanf(buf, "%d%d%d%d%d", &argv[1], &argv[2], &argv[3], &argv[4], &argv[5]);
	if ((argv[4] == 0) && (argv[5] == 0))
	{
		argv[3] = 1;
	}
}

int main()
{
	char op[16];
	k = 0;
	while (scanf("%s", op) != EOF)
	{
		if (op[0] < 'a')
		{
			op[0] += 'a' - 'A';
		}
		switch (op[0])
		{
			case 'd':
			{
				getlinenum();
				n = argv[1];
				set_init();
				break;
			}
			case 'c':
			{
				int i, st, ed;
				getlinenum();
				for (i = 1, st = argv[1], ed = argv[2]; i <= argv[3]; ++i, st += argv[5], ed += argv[4])
				{
					set_connect(st, ed);
				}
				break;
			}
			case 'q':
			{
				int i, st, ed;
				int s1 = 0;
				int s2 = 0;
				getlinenum();
				for (i = 1, st = argv[1], ed = argv[2]; i <= argv[3]; ++i, st += argv[5], ed += argv[4])
				{
					if (set_isconnect(st, ed))
					{
						++s1;
					}
					else
					{
						++s2;
					}
				}
				printf("%d - %d\n", s1, s2);
				break;
			}
			default:
			{
				break;
			}
		}
	}
	return 0;
}
