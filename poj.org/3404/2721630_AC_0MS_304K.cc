#include <iostream>
#include <algorithm>

using namespace std;

int speed[128];

int main()
{
	int i, n, m;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cin >> speed[i];
	}
	speed[n + 1] = speed[n];
	sort(speed + 1, speed + 1 + n);
	m = 1;
	int s = 0;
	while (n > 3)
	{
		s += speed[n] + speed[1] + min(2 * speed[2], (speed[1] + speed[n - 1]));
		n -= 2;
	}
	if (n < 3)
	{
		s += speed[2];
	}
	else
	{
		s += speed[3] + speed[2] + speed[1];
	}
	cout << s;
	return 0;
}
