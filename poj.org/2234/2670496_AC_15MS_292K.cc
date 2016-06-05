#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int i, nim, m;
		nim = 0;
		for (i = 1; i <= n; ++i)
		{
			cin >> m;
			nim ^= m;
		}
		if (nim == 0)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}
