#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int m(0);
	int ans[64];
	while (n > 1)
	{
		ans[m++] = n / 2;
		n = (n + 1) / 2;
	}
	cout << m << endl;
	for (int i = 0; i < m; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
