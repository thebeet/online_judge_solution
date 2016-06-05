#include <iostream>

using namespace std;

int main()
{
	int i, st, change, end;
	change = 7;
	end = (1 << 21) - 2;
	st = 0;
	for (i = 1; i <= 20; ++i)
	{
		int m;
		cin >> m;
		st |= (1 << i) * (m & 1);
	}
	for (i = 0; i < (1 << 20); ++i)
	{
		int b_st = st;
		int b_i = i;
		int k = 0;
		while (b_i > 0)
		{
			++k;
			if ((b_i & 1) > 0)
			{
				b_st ^= (change << k);
			}
			b_i >>= 1;
		}
		if ((b_st & end) == 0)
		{
			break;
		}
	}
	int ans = 0;
	while (i > 0)
	{
		if ((i & 1) > 0)
		{
			++ans;
		}
		i >>= 1;
	}
	cout << ans << endl;
	return 0;
}
