#include <iostream>

#define INT long long

using namespace std;

INT ans[1000010];

int main()
{
	int i, n;
	cin >> n;
	ans[1] = 1;
	ans[2] = 2;
	for (i = 3; i <= n; ++i)
	{
		ans[i] = ans[i - 1];
		++i;
		ans[i] = (ans[i - 2] + ans[i >> 1]) % 1000000000;
	}
	cout << ans[n] << endl;
	return 0;
}
