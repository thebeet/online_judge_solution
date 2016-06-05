#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int dp[512];
	vector<string> dic; 
	string mess;
	int w, l;
	cin >> w >> l >> mess;
	memset(dp, 10, sizeof(dp));
	for (int i = 0; i < w; ++i)
	{
		string word;
		cin >> word;
		dic.push_back(word);
	}
	for (int i = 0; i < l; ++i)
	{
		if (i == 0)
		{
			dp[i] = 0;
		}
		else
		{
			dp[i] = min(dp[i], dp[i - 1] + 1);
		}
		for (vector<string>::iterator vit = dic.begin(); vit != dic.end(); ++vit)
		{
			int i1(i);
			int pass(0);
			int i2(0);
			for ( ; i2 < vit->size(); ++i2, ++i1)
			{
				while ((i1 < l) && (mess[i1] != (*vit)[i2]))
				{
					++pass;
					++i1;
				}
				if (i1 == l)
				{
					break;
				}
			}
			if (i2 == vit->size())
			{
				dp[i + i2 + pass] = min(dp[i + i2 + pass], dp[i] + pass);
			}
		}
	}
	dp[l] = min(dp[l], dp[l - 1] + 1);
	cout << dp[l] << endl;
	return 0;
}
