#include <iostream>
#include <algorithm>

using namespace std;

int inparr[128];
int outarr[128];

int main()
{
	int i, n, k;
	cin >> n >> k;
	for (i = 1; i <= n; ++i)
	{
		cin >> inparr[i];
	}
	sort(inparr + 1, inparr + 1 + n);
	if (inparr[n] < 0)
	{
		if ((k & 1) == 1)
		{
			for (i = 1; i <= k; ++i)
			{
				cout << inparr[i] << endl;
			}
		}
		else
		{
			for (i = 1; i <= k; ++i)
			{
				cout << inparr[n - i + 1] << endl;
			}
		}
	}
	else
	{
		int p1 = 1;
		int p2 = n;
		outarr[0] = 0;
		if ((k & 1) == 1)
		{
			outarr[++outarr[0]] = inparr[n];
			--p2;
		}
		for (i = 0; i < k; i += 2)
		{
			if (inparr[p1] * inparr[p1 + 1] > inparr[p2] * inparr[p2 - 1])
			{
				outarr[++outarr[0]] = inparr[p1++];
				outarr[++outarr[0]] = inparr[p1++];
			}
			else
			{
				outarr[++outarr[0]] = inparr[p2--];
				outarr[++outarr[0]] = inparr[p2--];
			}
		}
		sort(outarr + 1, outarr + 1 + k);
		for (i = k; i >= 1; --i)
		{
			cout << outarr[i] << endl;
		}
	}
	return 0;
}
