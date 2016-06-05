#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int per[32][32];
struct letter
{
	char ch;
	int id;
}letters[32];

bool cmp(const letter &l1, const letter &l2)
{
	return (l1.ch < l2.ch);
}

int main()
{
	string inp;
	while (cin >> inp)
	{
		int i, n;
		memset(per, 0, sizeof(per));
		n = inp.size();
		for (i = 0; i < n; ++i)
		{
			letters[i].ch = inp[i];
			letters[i].id = i;
		}
		sort(letters, letters + n, cmp);
		
		for (i = 0; i < n; ++i)
		{
			per[11][letters[i].id] = i;
		}
		memcpy(per[31], per[11], sizeof(per[11]));
		for (i = 12; i <= 21; ++i)
		{
			next_permutation(per[11], per[11] + n);
			memcpy(per[i], per[11], sizeof(per[11]));
		}
		memcpy(per[11], per[31], sizeof(per[11]));
		for (i = 10; i >= 1; --i)
		{
			prev_permutation(per[11], per[11] + n);
			memcpy(per[i], per[11], sizeof(per[11]));
		}
		memcpy(per[11], per[31], sizeof(per[11]));
		
		int ans, ansp;
		ans = 0;
		for (i = 1; i <= 21; ++i)
		{
			int j;
			/*for (j = 0; j < n; ++j)
			{
				cout << per[i][j] << " ";
			}
			cout << endl;
			for (j = 0; j < n; ++j)
			{
				cout << letters[per[i][j]].ch << " ";
			}
			cout << endl;*/
			int abx = 100;
			for (int j = 1; j < n; ++j)
			{
				int d = letters[per[i][j]].ch - letters[per[i][j - 1]].ch;
				if (d < 0)
				{
					d = -d;
				}
				if (d < abx)
				{
					abx = d;
				}
			}
			if (abx > ans)
			{
				ansp = i;
				ans = abx;
			}
		}
		for (i = 0; i < n; ++i)
		{
			cout << letters[per[ansp][i]].ch;
		}
		cout << ans << endl;
	}
	return 0;
}
