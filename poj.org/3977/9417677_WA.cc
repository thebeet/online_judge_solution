#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long myabs(long long n)
{
	if (n > 0LL) return n;
	else return -n;
}

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		long long tv = 10000000000000000LL;
		int count = 0;
		long long arr[n];
		long long allsum[n + 1];
		memset(allsum, 0, sizeof(allsum));
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			allsum[i + 1] = allsum[i] + arr[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j < n; ++j)
			{
				long long subsum = allsum[j + 1] - allsum[i];
				if (myabs(subsum) == tv)
				{
					count = min(count, j - i + 1);
				}
				else if (myabs(subsum) < tv)
				{
					tv = subsum;
					count = j - i + 1;
				}

			}
		}
		cout << tv << " " << count << endl;

	}	
}
