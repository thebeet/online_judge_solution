#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		int arr[2][n];
		for (int k = 0; k < 2; ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				cin >> arr[k][i];
			}
			sort(arr[k], arr[k] + n, greater<int>());
		}
		int p = 0;
		int ans(0);
		for (int i = 0; i < n; ++i)
		{
			while ((p < n) && (arr[1][p] >= arr[0][i]))
			{
				++p;
			}
			if (p == n) break;
			ans += 2;
			arr[0][i] = -1;
			arr[1][p] = -1;
			++p;
		}
		map<int, int> hash;
		hash.clear();
		for (int i = 0; i < n; ++i)
		{
			if (arr[1][i] >= 0)
			{
				++hash[arr[1][i]];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (arr[0][i] >= 0)
			{
				if (hash[arr[0][i]] > 0)
				{
					--hash[arr[0][i]];
					++ans;
				}
			}
		}
		cout << (ans - n) * 200 << endl;
	}
	return 0;
}
