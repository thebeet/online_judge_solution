#include <iostream>

using namespace std;

bool troop[1024];

int main()
{
	int r, n;
	while ((cin >> r >> n), r >= 0)
	{
		int i, j, ans;
		memset(troop, false, sizeof(troop));
		ans = 0;
		
		for (i = 1; i <= n; ++i)
		{
			int m;
			cin >> m;
			troop[m] = true;
		}
		for (i = 0; i <= 1000; ++i)
		{
			if (troop[i])
			{
				for (j = i + r; j > i; --j)
				{
					if (troop[j])
					{
						break;
					}
				}
				i = j + r;
				++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
