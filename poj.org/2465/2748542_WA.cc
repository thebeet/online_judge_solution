#include <iostream>
#include <algorithm>

using namespace std;

int dp[16384][256];

int main()
{
	int i, totlen;
	memset(dp, 127, sizeof(dp));
	dp[0][100] = 0;
	cin >> totlen;
	
	int prepos = 0;
	int mxgas = 100;
	int mngas = 100;
	
	for (;;)
	{
		int pos, price;
		bool endflag = false;
		if ((cin >> pos >> price) == false)
//		if (pos == -1)
		{
			pos = totlen;
			endflag = true;
		}
		int dist = pos - prepos;
		if (dist > mxgas)
		{
			cout << "Impossible" << endl;
			return 0;
		}
		else
		{
			mngas = max(mngas, dist);
			for (i = mngas; i <= mxgas; ++i)
			{
				dp[pos][i - dist] = dp[prepos][i];
			}
			if (endflag)
			{
				break;
			}
			mngas -= dist;
			mxgas = 200;
			for (i = mngas; i < 200; ++i)
			{
				dp[pos][i + 1] = min(dp[pos][i + 1], dp[pos][i] + price);
			}
			prepos = pos;
		}
	}
	
	int ans = 0x3FFFFFFF;
	for (i = 100; i <= 200; ++i)
	{
		ans = min(ans, dp[totlen][i]);
	}
	cout << ans << endl;
	
	return 0;
}
