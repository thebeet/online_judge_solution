#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n;
	int m;
	cin >> n >> m;
	n *= 3LL;
	for (int i = 0; i < m; ++i)
	{
		long long d;
		cin >> d;
		n -= d;
		if (n < 0)
		{
			cout << "Free after " << i + 1 << " times." << endl;
			return 0;
		}
	}
	cout << "Team.GOV!" << endl;
	return 0;
}
