#include <iostream>

using namespace std;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, n, pr, m, st;
		bool stack[32];
		cin >> n;
		pr = 1;
		st = 0;
		for (i = 1; i <= n; ++i)
		{
			cin >> m;
			for ( ; pr <= m; ++pr)
			{
				stack[pr] = true;
			}
			for (j = m; stack[j] == false; --j)
			{
			}
			stack[j] = false;
			cout << m - j + 1 << ((i == n) ? "\n" : " ");
		}
	}
	return 0;
}
