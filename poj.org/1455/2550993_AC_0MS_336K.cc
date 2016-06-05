#include <iostream>

using namespace std;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int n;
		cin >> n;
		cout << (n / 2) * ((n - 1) / 2) << endl;
	}
	return 0;
}
