#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class node
{
public:
	node(int a_v, int a_c, int a_mode) :
		v(a_v), c(a_c), mode(a_mode)
	{
	
	}
	int v;
	int c, mode;
};

vector< vector<node > > graph;

const int M_AND = 0;
const int M_OR = 1;
const int M_XOR = 2;

int stat[1024];

bool submit(const int p, const int x);

bool expend(const int p)
{
	for (int i = 0; i < graph[p].size(); ++i)
	{
		if (graph[p][i].mode == M_AND)
		{
			if ((stat[p] == 1) && (graph[p][i].c == 0))
			{
				if (submit(graph[p][i].v, 0) == false) return false;
			}
		}
		else if (graph[p][i].mode == M_OR)
		{
			if ((stat[p] == 0) && (graph[p][i].c == 1))
			{
				if (submit(graph[p][i].v, 1)) return false;
			}
		}
		else if (graph[p][i].mode == M_XOR)
		{
			if (submit(graph[p][i].v, stat[p] ^ 1)) return false;
		}
	}
}

bool submit(const int p, const int x)
{
	if (stat[p] == -1)
	{
		stat[p] = x;
		
	}
	else if (stat[p] != x)
	{
		return false;
	}
	return true;
}

int main()
{
	int i, n, m;
	scanf("%d%d", &n, &m);
	graph.resize(n);
	memset(stat, -1, sizeof(stat));
	char inp[16];
	for (i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d%d%d%s", &a, &b, &c, inp);
		int mode;
		if (inp[0] == 'A')
		{
			mode = M_AND;
			if (c == 1)
			{
				if ((submit(a, 1) == false) || (submit(b, 1) == false))
				{
					printf("NO\n");
					return 0;
				}
			}
			else
			{
				if (stat[a] == 0)
				{
					if (submit(b, 0) == false)
					{
						printf("NO\n");
						return 0;
					}
				}
				if (stat[b] == 0)
				{
					if (submit(a, 0) == false)
					{
						printf("NO\n");
						return 0;
					}
				}
			}
		}
		else if (inp[0] == 'O')
		{
			mode = M_OR;
			if (c == 0)
			{
				if ((submit(a, 0) == false) || (submit(b, 0) == false))
				{
					printf("NO\n");
					return 0;
				}
			}
			else
			{
				if (stat[a] == 0)
				{
					if (submit(b, 1) == false)
					{
						printf("NO\n");
						return 0;
					}
				}
				if (stat[b] == 0)
				{
					if (submit(a, 1) == false)
					{
						printf("NO\n");
						return 0;
					}
				}
			}
		}
		else if (inp[0] == 'X')
		{
			mode = M_XOR;
			if (stat[a] >= 0)
			{
				if (submit(b, stat[a] ^ 1) == false)
				{
					printf("NO\n");
					return 0;
				}
			}
			else if (stat[b] >= 0)
			{
				if (submit(a, stat[b] ^ 1) == false)
				{
					printf("NO\n");
					return 0;
				}
			}
		}
		graph[a].push_back(node(b, c, mode));
		graph[b].push_back(node(a, c, mode));
	}
	printf("YES\n");
	return 0;
}
