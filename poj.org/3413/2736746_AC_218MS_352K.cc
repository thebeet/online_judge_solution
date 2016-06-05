#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

double a[16]; 
double b[16];
double d[16];
double s[16];

int prem[16];

int ans[16];

int main()
{
	int i, n;
	double dd;
	cin >> n >> dd;
	for (i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i] >> s[i];
		d[i] = b[i] - a[i];
		prem[i] = i;
	}
	double mp(-1.0);
	double p;
	for (;;)
	{
		p = 1.0;
		double xp(dd);
		for (i = 0; i < n; ++i)
		{
			if (xp < a[prem[i]])
			{
				p = 0.0;
				break;
			}
			if (xp < b[prem[i]])
			{
				(p *= (xp - a[prem[i]])) /= d[prem[i]];
			}
			xp += s[prem[i]];
		}
		if (p > mp)
		{
			mp = p;
			memcpy(ans, prem, sizeof(ans));
		}
		if (next_permutation(prem, prem + n) == false)
		{
			break;
		}
	}
	printf("%3lf\n", mp);
	for (i = 0; i < n; ++i)
	{
		cout << ans[i] + 1 << ((i == n - 1) ? '\n' : ' ');
	}
	return 0;
}
