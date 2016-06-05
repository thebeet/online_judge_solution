#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int m, t, u, f, d;
	cin >> m >> t >> u >> f >> d;
	f <<= 1;
	u += d;
	int s(0);
	int i;
	for (i = 0; i < t; ++i)
	{
		char c;
		cin >> c;
		if (c == 'f')
		{
			s += f;
		}
		else
		{
			s += u;
		}
		if (s > m) break;
	}
	cout << i << endl;
	return 0;
}
