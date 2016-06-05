#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[30010];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int n;
		scanf("%d", &n);
		scanf("%d", &arr[0]);
		int ans(1);
		int st = 0;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			if (st == 0)
			{
				if (arr[i - 1] > arr[i])
				{
					++ans;
					st ^= 1;
				}
			}
			else
			{
				if (arr[i - 1] < arr[i])
				{
					++ans;
					st ^= 1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
