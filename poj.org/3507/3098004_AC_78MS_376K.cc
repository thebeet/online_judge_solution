#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[6];
	int i;
	for (;;)
	{
		for (i = 0; i < 6; ++i)
		{
			cin >> a[i];
		}
		sort(a, a + 6);
		int s(0);
		for (i = 1; i < 5; ++i)
		{
			s += a[i];
		}
		if (a[5] == 0)
		{
			return 0;
		}
		cout << (double(s) / 4) << endl;
	}
	return 0;
}
