#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> mat[2048][2048];
int mm[2048][2048];

int stack[2048];
int height[2048];
int ans(0);

void push(int detail, int h)
{
	stack[++stack[0]] = detail;
	height[stack[0]] = h;
}

void pop(int &h)
{
	h += height[stack[0]];
	ans = max(ans, stack[stack[0]] * h);
	--stack[0];
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int i, j;
		ans = 0;
		memset(mat, 0, sizeof(mat));
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= m; ++j)
			{
				scanf("%d", &mm[i][j]);
				if (mm[i][j] == 1)
				{
					mat[i][j].first = mat[i][j - 1].first + 1;
					mat[i][j].second = mat[i - 1][j].second + 1;
				}
			}
		}
		
		for (i = 1; i <= n; ++i)
		{
			memset(stack, 0, sizeof(stack));
			for (j = 1; j <= m; ++j)
			{
				int h(0);
				while ((stack[0] > 0) && (stack[stack[0]] > mat[i][j].second))
				{
					pop(h);
				}
				push(mat[i][j].second, h + 1);
			}
			int h(0);
			while (stack[0] > 0)
			{
				pop(h);
			}
		}
		for (j = 1; j <= m; ++j)
		{
			memset(stack, 0, sizeof(stack));
			for (i = 1; i <= n; ++i)
			{
				int h(0);
				while ((stack[0] > 0) && (stack[stack[0]] > mat[i][j].first))
				{
					pop(h);
				}
				push(mat[i][j].first, h + 1);
			}
			int h(0);
			while (stack[0] > 0)
			{
				pop(h);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
