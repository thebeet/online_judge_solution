#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int use[2][256];

int main()
{
	string str[2];
	cin >> str[1] >> str[0];
	memset(use, 0, sizeof(use));
	for (unsigned int k = 0; k <= 1; ++k)
	{
		for (unsigned int i = 0; i < str[k].size(); ++i)
		{
			++use[k][(int)str[k][i]];
		}
		sort(use[k], use[k] + 128);
	}
	if (memcmp(use[0], use[1], 128) == 0)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
