#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string num[16];

int main()
{
	int i, n;
	cin >> n;
	num[0] = "{}";
	for (i = 1; i < 16; ++i)
	{
		num[i] = "{{}";
		for (int j = 1; j < i; ++j)
		{
			num[i] += "," + num[j];
		}
		num[i] += "}";
	}
	for (i = 1; i <= n; ++i)
	{
		string a, b;
		int na(0), nb(0);
		cin >> a >> b;
		while (num[na] != a)
		{
			++na;
		}
		while (num[nb] != b)
		{
			++nb;
		}
		cout << num[na + nb] << endl;
	}
	return 0;
}
