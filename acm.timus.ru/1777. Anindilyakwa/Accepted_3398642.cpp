#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

long long st[1000010];

int main()
{
	int i;
	for (i = 0; i < 3; ++i)
	{
		cin >> st[i];
	}
	for ( ; ; ++i)
	{
		sort(st, st + i);
		long long d = st[1] - st[0];
		for (int j = 2; j < i; ++j)
		{
			long long dt = st[j] - st[j - 1];
			d = min(d, dt);
		}
		if (d == 0) break;
		st[i] = d;
	}
	cout << i - 2 << endl;
	return 0;
}
