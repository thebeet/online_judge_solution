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
		}
		sort(arr[0], arr[0] + n);
		sort(arr[1], arr[1] + n, greater<int>());
		int ans(0);
		for (int i = 0; i < n; ++i)
		{
			if (arr[0][i] == -1) continue;
			for (int j = 0; j < n; ++j)
			{
				if (arr[1][j] == -1) continue;
				if (arr[0][i] > arr[1][j])
				{
					ans += 2;
					arr[0][i] = -1;
					arr[1][j] = -1;
					break;	
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (arr[0][i] == -1) continue;
			for (int j = 0; j < n; ++j)
			{
				if (arr[1][j] == -1) continue;
				if (arr[0][i] == arr[1][j])
				{
					ans += 1;
					arr[0][i] = -1;
					arr[1][j] = -1;
					break;	
				}
			}
		}
		cout << (ans - n) * 200 << endl;
	}
	return 0;
}
