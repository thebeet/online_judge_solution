#include <stdio.h>
#include <string.h>

const int MAXN = 6000010;

int father[MAXN];
int rank[MAXN];
int argc;
int argv[8];

void set_init(int n)
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		father[i] = i;
	}
	memset(rank, 0, sizeof(rank));
}

int find(int a)
{
	if (father[a] != a)
	{
		father[a] = find(father[a]);
	}
	return father[a];
}

void set_connect(int a, int b)
{
	int fa = find(a);
	int fb = find(b);
	if (rank[a] < rank[b])
	{
		father[fa] = fb;
	}
	else
	{
		father[fb] = fa;
		 if (rank[a] == rank[b])
		 {
			 ++rank[a];
		 }
	}
}

inline bool set_isconnect(int a, int b)
{
	return (find(a) == find(b));
}

void getlinenum(void)
{
	argc = 0;
	argv[3] = 1;
	argv[4] = 1;
	argv[5] = 0;
	char ch;
	while (scanf("%c", &ch), ch == ' ')
	{
		scanf("%d", &argv[++argc]);
	}
}

int main()
{
	int n;
	char op[4];
	while (scanf("%c", op) != EOF)
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
				set_init(n);
				break;
			}
			case 'c':
			{
				int i, st, ed;
				getlinenum();
				for (i = 1, st = argv[1], ed = argv[2]; (i <= argv[3]) && (st <= n) && (ed <= n) && (st > 0) && (ed > 0); ++i, st += argv[5], ed += argv[4])
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
				for (i = 1, st = argv[1], ed = argv[2]; (i <= argv[3]) && (st <= n) && (ed <= n) && (st > 0) && (ed > 0); ++i, st += argv[5], ed += argv[4])
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
				printf("ERROR!\n");
				break;
			}
		}
	}
	return 0;
}
