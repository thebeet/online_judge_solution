#include <stdio.h>
#include <string.h>

const int MAXN = 6000010;

int father[MAXN];
int stack[MAXN];
int argv[16];
int n;
char buf[1024];

void set_init()
{
	memset(father, 0, sizeof(father));
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
	if (fa != fb)
	{
		father[fa] = fb;
	}
}

bool set_isconnect(int a, int b)
{
	return (find(a) == find(b));
}

void getlinenum(void)
{
	int ret;
	gets(buf);
	ret = sscanf(buf, "%d%d%d%d%d", &argv[1], &argv[2], &argv[3], &argv[4], &argv[5]);
	if (ret < 5)
	{
		argv[5] = 0;
		if (ret < 4)
		{
			argv[4] = 1;
			if (ret < 3)
			{
				argv[3] = 1;
			}
		}
	}
}

int main()
{
	char op[16];
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
				if ((argv[4] == 0) && (argv[5] == 0) && (argv[3] != 0))
				{
					argv[3] = 1;
				}
				for (i = 1, st = argv[1], ed = argv[2]; i <= argv[3]; ++i, st += argv[5], ed += argv[4])
				{
					set_connect(st, ed);
				}
				break;
			}
			case 'q':
			{
				int i, st, ed;
				int b = 1;
				int s1 = 0;
				int s2 = 0;
				getlinenum();
				if ((argv[4] == 0) && (argv[5] == 0) && (argv[3] != 0))
				{
					b = argv[3];
					argv[3] = 1;
				}
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
				printf("%d - %d\n", s1 * b, s2 * b);
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
