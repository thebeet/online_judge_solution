#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	c += d;
	while (true)
	{
		c -= d;
		if (a >= c)
		{
			cout << a << endl;
			return 0;
		}
		a += b;
		if (a >= c)
		{
			cout << c << endl;
		}
	}
	return 0;
}
