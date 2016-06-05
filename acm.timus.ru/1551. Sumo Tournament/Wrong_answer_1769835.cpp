#include <iostream>
#include <string>

using namespace std;

string name[1024];

int main()
{
	int i, j, n, ans;
	cin >> n;
	for (i = 0; i < (1 << n); ++i)
	{
		string tmp;
		cin >> tmp >> name[i];
	}
	for (ans = 0; ans < n; ++ans)
	{
		int mask = (1 << ans) - 1;
		for (i = 0; i < (1 << n); ++i)
		{
			int st = (i ^ (i & mask)) ^ (1 << ans);
			int ed = st + mask;
			for (j = st; j <= ed; ++j)
			{
				if (name[i] == name[j])
				{
					break;
				}
			}
			if (j <= ed)
			{
				break;
			}
		}
		if (i < (1 << n))
		{
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
