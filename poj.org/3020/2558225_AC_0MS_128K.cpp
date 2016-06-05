#include <stdio.h>
#include <string.h>

int from[10000];
bool gone[10000];
char map[64][64];
int n, m;

bool hungary_dfs(int pp)
{
	int i;
	int x = pp / 100;
	int y = pp % 100;
	if (map[x][y] != '*')
	{
		return false;
	}
	gone[pp] = true;
	if (((from[pp + 1] == 0) && (map[x][y + 1] == '*')) || ((gone[from[pp + 1]] == false) && (hungary_dfs(from[pp + 1]) == true)))
	{
		from[pp] = pp + 1;
		from[pp + 1] = pp;
		return true;
	}
	if (((from[pp - 1] == 0) && (map[x][y - 1] == '*')) || ((gone[from[pp - 1]] == false) && (hungary_dfs(from[pp - 1]) == true)))
	{
		from[pp] = pp - 1;
		from[pp - 1] = pp;
		return true;
	}
	if (((from[pp + 100] == 0) && (map[x + 1][y] == '*')) || ((gone[from[pp + 100]] == false) && (hungary_dfs(from[pp + 100]) == true)))
	{
		from[pp] = pp + 100;
		from[pp + 100] = pp;
		return true;
	}
	if (((from[pp - 100] == 0) && (map[x - 1][y] == '*')) || ((gone[from[pp - 100]] == false) && (hungary_dfs(from[pp - 100]) == true)))
	{
		from[pp] = pp - 100;
		from[pp - 100] = pp;
		return true;
	}
	
	return false;
}

int hungary(void)
{
	int k, i, j;
	memset(from, 0, sizeof(from));
	
	for (k = 1; ; ++k)
	{
		memset(gone, false, sizeof(gone));
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= m; ++j)
			{
				int pp = i * 100 + j;
				if ((from[pp] == 0) && (gone[pp] == false))
				{
					if (hungary_dfs(pp))
					{
						break;
					}
				}
			}
			if (j <= m)
			{
				break;
			}
		}
		if (i > n)
		{
			break;
		}
	}
	return k - 1;
}

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 1; ti <= tn; ++ti)
	{
		int i, j, s;
		memset(map, 'o', sizeof(map));
		s = 0;
		
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; ++i)
		{
			scanf("%s", map[i] + 1);
			for (j = 1; j <= m; ++j)
			{
				if (map[i][j] == '*')
				{
					++s;
				}
			}
		}
		printf("%d\n", s - hungary());
	}
	return 0;
}
