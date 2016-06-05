#include <iostream>
#include <string>

#define INT long long

using namespace std;

string inp1, inp2;

int main()
{
	int eq;
	unsigned int i;
	INT ans;
	ans = 0;
	while ((cin >> inp1), inp1[0] != '#')
	{
		cin >> inp2;
		eq = 0;
		ans = 0;
		for (i = 0; i < inp1.size(); ++i)
		{
			if ((inp1[i] >= '0') && (inp1[i] <= '9'))
			{
				if (eq == 0)
				{
					if (inp1[i] > inp2[i])
					{
						eq = 1;
					}
					if (inp1[i] < inp2[i])
					{
						eq = -1;
					}
				}
			}
			else
			{
				ans *= (INT)10;
				if (eq == 0)
				{
					ans += (INT)9 - (INT)(inp2[i] - '0');
				}
				if ((eq == 1) && (ans == 0))
				{
					ans = (INT)10;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
