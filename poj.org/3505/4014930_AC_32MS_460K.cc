#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> pos[2560];
int belt[64];

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		int h, l;
		int i, j;
		cin >> h >> l;
		int maxcar(0);
		for (i = 0; i < h; ++i)
		{
			for (j = 0; j < l; ++j)
			{
				int car;
				cin >> car;
				if (car > 0)
				{
					pos[car].first = i;
					pos[car].second = j;
					maxcar = max(maxcar, car);
				}
			}
			belt[i] = 0;
		}
		pos[0].first = 0;
		pos[0].second = 0;
		int ans(0);
		for (int i = 1; i <= maxcar; ++i)
		{
			int ab = abs(pos[i].second - belt[pos[i].first]);
			ans += 5 * min(ab, l - ab);
			belt[pos[i].first] = pos[i].second;
			ans += 20 * pos[i].first;
		}
		cout << ans << endl;
	}
	return 0;
}
