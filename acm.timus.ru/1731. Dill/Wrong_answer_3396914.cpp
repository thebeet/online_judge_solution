#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int s = 0;
	for (int i = 1; i <= n; ++i)
	{
		cout << i << " ";
		s += i;
	}
	cout << endl;
	for (int i = 1; i < m; ++i)
	{
		cout << n + i << " ";
		s += n + i;
	}
	if (s % 2 == 0) cout << 11111 << endl;
	else cout << 22222 << endl;
}
