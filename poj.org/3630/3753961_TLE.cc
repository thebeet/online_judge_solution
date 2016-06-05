#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string inp[10010];

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 0; ti < tn; ++ti)
	{
		int i, n;
		cin >> n;
		for (i = 0; i < n; ++i)
		{
			cin >> inp[i];
		}
		sort(inp, inp + n);
		for (i = 1; i < n; ++i)
		{
			if (inp[i - 1].size() <= inp[i].size())
			{
				int j;
				for (j = 0; j < inp[i - 1].size(); ++j)
				{
					if (inp[i - 1][j] != inp[i][j])
					{
						break;
					}
				}
				if (j == inp[i - 1].size())
				{
					break;
				}
			}
		}
		cout << ((i < n) ? "NO" : "YES") << endl; 
	}
	return 0;
}
