#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	if (max(n, m) == 0)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		int d = min((min(n, m) * 2 + 1), m + n);
		d = (int)sqrt((double)d + 0.1);
		cout << d << endl;
	}
	return 0;
}
