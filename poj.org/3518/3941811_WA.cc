#include <iostream>
#include <algorithm>

using namespace std;

bool prime[1600000];

int main()
{
	memset(prime, true, sizeof(prime));
	for (int i = 2; i <= 1000; ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 1299709; j += i)
			{
				prime[j] = false;
			}
		}
	}
	int n;
	while ((cin >> n), n > 0)
	{
		int i = n;
		int j = n;
		while (prime[i] == false) ++i;
		while (prime[j] == false) --j;
		cout << i - j << endl;
	}
	return 0;
}
