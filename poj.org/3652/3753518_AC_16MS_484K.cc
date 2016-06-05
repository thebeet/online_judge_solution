#include <iostream>
#include <algorithm>

using namespace std;

int ans[32];
bool gone[65536];

void initnum(const int x)
{
	for (int i = 0; i < 16; ++i)
	{
		ans[i] = (x & (1 << i)) ? 1 : 0;
	}
}

bool addnum(const int x)
{
	if (gone[x])
	{
		return false;
	}
	gone[x] = true;
	for (int i = 0; i < 16; ++i)
	{
		if (((x & (1 << i)) ? 1 : 0) != ans[i])
		{
			ans[i] = 2;
		}
	}
	return true;
}

int main()
{
	int a, b, c, s;
	while (cin >> a >> b >> c >> s)
	{
		memset(gone, false, sizeof(gone));
		initnum(s);
		while (addnum(s))
		{
			s = ((a * s) % c + b) % c;
		}
		for (int i = 15; i >= 0; --i)
		{
			if (ans[i] == 2)
			{
				cout << "?";
			}
			else
			{
				cout << ans[i];
			}
		}
		cout << endl;
	}
	return 0;
}
