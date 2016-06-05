#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	if (n == 2)
	{
		cout << 0 << endl;
		return 0;
	}
	if (k <= n / 2) k = n - k; else k = k - 1;
	cout << k - 2 << endl;
	return 0;
}
