#include <iostream>
#include <string>

using namespace std;

int main()
{
	int k, n;
	cin >> k >> n;
	int r = 0;
	for (int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;
		r = r + c - k;
		if (r < 0) r = 0;
	}
	cout << r;
	return 0;
}
