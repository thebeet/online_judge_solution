#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> lans;

string ans[128];

int main()
{
	int i, n, k;
	cin >> n;
	k = 0;
	string lan;
	for (i = 1; i <= n; ++i)
	{
		cin >> lan;
		if ((lans[lan]++) == 0)
		{
			ans[++k] = lan;
		}
		else
		{
			if (n > 2)
			{
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	if (k > 2)
	{
		cout << k << endl;
		for (i = 1; i <= k; ++i)
		{
			cout << ans[i] << '-' << "dasffish"<< endl;
		}
	}
	else if (k == 1)
	{
		cout << 0 << endl;
	}
	else if (k == 2)
	{
		cout << 1 << endl;
		cout << ans[1] << '-' << ans[2] << endl;
	}
	return 0;
}
