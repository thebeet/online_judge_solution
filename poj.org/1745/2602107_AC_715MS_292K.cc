#include <iostream>

using namespace std;

bool enb[2][100];

int main()
{
	int i, j, n, k, m, pk;
	int p1 = 0;
	int p2 = 1;
	memset(enb, false, sizeof(enb));
	enb[0][0] = true;
	cin >> n >> k;
	pk = 10000 * k * k;
	for (i = 1; i <= n; ++i)
	{
		cin >> m;
		memset(enb[p2], false, 100);
		for (j = 0; j < k; ++j)
		{
			if (enb[p1][j])
			{
				enb[p2][(j + m + pk) % k] = true;
				enb[p2][(j - m + pk) % k] = true;
			}
		}
		p1 ^= 1;
		p2 ^= 1;
	}
	if (enb[p1][0])
	{
		cout << "Divisible" << endl;
	}
	else
	{
		cout << "Not divisible" << endl;
	}
	return 0;
}
