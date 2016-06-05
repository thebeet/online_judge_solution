#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int i, n, k;
	cin >> n >> k;
	for (i = 1; i <= k; ++i)
	{
		int s, t, r;
		cin >> s >> t >> r;
		int T(t + r);
		int S = s * t;
		int TN = (n - 1) / S;
		cout << TN * T + ((n - S * TN + s - 1) / s) << endl;
	}
	return 0;
}
