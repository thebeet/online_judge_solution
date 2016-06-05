#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long INT;

INT tripets[4][200010];

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		int i;
		INT sum = 0;
		for (i = 0; i < n; ++i)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			tripets[1][i] = x - y;
			tripets[2][i] = y - z;
			tripets[3][i] = z - x;
		}
		sort(tripets[1], tripets[1] + n);
		sort(tripets[2], tripets[2] + n);
		sort(tripets[3], tripets[3] + n);
		for (i = 0; i < n; ++i)
		{
			sum += (tripets[1][i] + tripets[2][i] + tripets[3][i]) * (i + i - n - 1);
		}
		cout << sum / (INT)2 << endl;
	}
	return 0;
}
