#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		while (n > 1)
		{
			if ((n & 1) == 1)
			{
				break;
			}
			n >>= 1;
		}
		if (n > 1)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}
