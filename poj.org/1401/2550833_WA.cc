#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 0;
		while (n >= 5)
		{
			n /= 5;
			sum += n;
		}
		cout << sum << endl;
	}
	return 0;
}
