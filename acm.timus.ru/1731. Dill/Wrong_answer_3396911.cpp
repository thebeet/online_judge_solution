#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	cout << 500000;
	for (int i = 1; i < n; ++i)
	{
		cout << " " << i;
	}
	cout << endl;
	cout << 30000000;
	for (int i = 1; i < m; ++i)
	{
		cout << " " << n + i;
	}
	cout << endl;
}
