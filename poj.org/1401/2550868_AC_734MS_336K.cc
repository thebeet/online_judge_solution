#include <iostream>

using namespace std;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int n;
		int sum = 0;
		cin >> n;
		while (n >= 5)
		{
			n /= 5;
			sum += n;
		}
		cout << sum << endl;
	}
	return 0;
}
