#include <iostream>
#include <string>

using namespace std;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		string tar, inp, inp1, inp2;
		int perm[256];
		int i, j, n;
		cin >> n;
		cin >> inp1 >> inp2;
		cin >> tar;
		inp = inp1 + inp2;
		
		memset(perm, 0, sizeof(perm));
		for (i = 0; i < n; ++i)
		{
			perm[i] = (i << 1) + 1;
			perm[i + n] = (i << 1);
		}
		
		for (i = 0; i <= n; ++i)
		{
			if (inp == tar)
			{
				break;
			}
			string pm(n * 2, ' ');
			for (j = 0; j < 2 * n; ++j)
			{
				pm[perm[j]] = inp[j];
			}
			inp = pm;
		}
		
		if (i <= n)
		{
			cout << ti << " " << i << endl;
		}
		else
		{
			cout << ti << " " << -1 << endl;
		}
	}
	return 0;
}
