#include <iostream>
#include <algorithm>

using namespace std;

int a[65536];
int st[4];

int main()
{
	int n;
	scanf("%d", &n);
	memset(st, 0, sizeof(st));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		for (int j = 3; j >= 1; --j)
		{
			if (a[i] != j)
			{
				++st[j];
			}
			else
			{
				for (int k = 1; k < j; ++k)
				{
					st[j] = min(st[j], st[k]);
				}
			}
		}
	}
	int ans1 = min(st[1], min(st[2], st[3]));
	memset(st, 0, sizeof(st));
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 3; j >= 1; --j)
		{
			if (a[i] != j)
			{
				++st[j];
			}
			else
			{
				for (int k = 1; k < j; ++k)
				{
					st[j] = min(st[j], st[k]);
				}
			}
		}
	}
	int ans2 = min(st[1], min(st[2], st[3]));
	cout << min(ans1, ans2) << endl;
	return 0;
}
