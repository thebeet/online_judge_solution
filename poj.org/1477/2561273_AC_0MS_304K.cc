#include <iostream>

using namespace std;

int array[1024];

int main()
{
	int ti, n;
	ti = 0;
	while ((cin >> n), n > 0)
	{
		int i, s, ans;
		cout << "Set #" << ++ti << endl;
		cout << "The minimum number of moves is ";

		memset(array, 0, sizeof(array));
		s = 0;
		ans = 0;

		for (i = 1; i <= n; ++i)
		{
			cin >> array[i];
			s += array[i];
		}
		
		s /= n;

		for (i = 1; i <= n; ++i)
		{
			if (array[i] > s)
			{
				ans += array[i] - s;
			}
			else
			{
				ans -= array[i] - s;
			}
		}

		cout << (ans >> 1) << "." << endl << endl;
	}
	return 0;
}




