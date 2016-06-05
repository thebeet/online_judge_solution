#include <iostream>

using namespace std;

long long ans[64];

int main()
{
	int ti, tn, i, n;
	ans[1] = 2;
	ans[2] = 3;
	for (i = 3; i <= 50; ++i)
	{
		ans[i] = ans[i - 1] + ans[i - 2];
	}
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		cin >> n;
		cout << "cenario #" << ti << ":\n" << ans[n] << endl << endl;
	}
	return 0;
}
