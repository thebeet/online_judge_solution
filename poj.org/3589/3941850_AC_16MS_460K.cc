#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		string inp1, inp2;
		cin >> inp1 >> inp2;
		bool num[16];
		memset(num, false, sizeof(num));
		for (int j = 0; j < 4; ++j)
		{
			num[inp1[j] - '0'] = true;
		}
		int ans1(0), ans2(0);
		for (int j = 0; j < 4; ++j)
		{
			if (inp1[j] == inp2[j])
			{
				++ans1;
			}
			if (num[inp2[j] - '0'])
			{
				++ans2;
			}
		}
		cout << ans1 << "A" << ans2 - ans1 << "B" << endl;
	}
	return 0;
}
