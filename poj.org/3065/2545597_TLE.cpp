#include <stdio.h>
#include <string.h>

const int MAXN = 6000010;

int father[MAXN];
int stack[MAXN];

//int rank[MAXN];
int argc;
int argv[16];
int n;

void set_init(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		father[i] = i;
	}
	//memset(rank, 0, sizeof(rank));
}

int find(int a, int h)
{
	if (h > 30000)
	{
		for (;;);
	}
	if (father[a] != a)
	{
		father[a] = find(father[a], h + 1);
	}
	return father[a];
	/*int pp = a;
	stack[0] = 0;
	while (father[pp] != pp)
	{
		stack[++stack[0]] = pp;
		pp = father[pp];
	}
	while (stack[0] > 1)
	{
		father[--stack[0]] = pp; 
	}
	return pp;*/
}

void set_connect(int a, int b)
{
	/*if ((a <= 0) || (b <= 0) || (a > n) || (b > n))
	{
		for (;;);
	}*/
	int fa = find(a, 0);
	int fb = find(b, 0);
	father[fa] = fb;
/*	if (rank[fa] < rank[fb])
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
	}*/
}

inline bool set_isconnect(int a, int b)
{
	/*if ((a <= 0) || (b <= 0) || (a > n) || (b > n))
	{
		for (;;);
	}*/
	return (find(a, 0) == find(b, 0));
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
		/*if (argc > 5)
		{
			for(;;);
		}*/
	}
	/*if ((argv[4] == 0) && (argv[5] == 0))
	{
		argv[3] = 1;
	}*/
}

int main()
{
	char op;
	while (scanf("%c", &op) != EOF)
	{
		if (op < 'a')
		{
			op += 'a' - 'A';
		}
		switch (op)
		{
			case 'd':
			{
				getlinenum();
				n = argv[1];
				set_init(n);
				/*if (n > 6000000)
				{
					for (;;);
				}*/
				break;
			}
			case 'c':
			{
				int i, st, ed;
				getlinenum();
				for (i = 1, st = argv[1], ed = argv[2]; (i <= argv[3])/* && (st <= n) && (ed <= n) && (st > 0) && (ed > 0) */; ++i, st += argv[5], ed += argv[4])
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
				for (i = 1, st = argv[1], ed = argv[2]; (i <= argv[3])/* && (st <= n) && (ed <= n) && (st > 0) && (ed > 0) */; ++i, st += argv[5], ed += argv[4])
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
