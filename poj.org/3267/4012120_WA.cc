#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int dp[512];
	vector< string > dic; 
	string mess;
	int w, l;
	cin >> w >> l;
	cin >> mess;
	memset(dp, 10, sizeof(dp));
	for (int i = 0; i <= mess.size(); ++i)
	{
		dp[i] = i;
	}
	for (int i = 0; i < w; ++i)
	{
		string word;
		cin >> word;
		dic.push_back(word);
	}
	for (int i = 0; i < mess.size(); ++i)
	{
		for (vector<string>::iterator vit = dic.begin(); vit != dic.end(); ++vit)
		{
			int i1(i);
			int pass(0);
			int i2(0);
			for ( ; i2 < vit->size(); ++i2, ++i1)
			{
				while ((i1 < mess.size()) && (mess[i1] != (*vit)[i2]))
				{
					++pass;
					++i1;
				}
				if (i1 == mess.size())
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
	cout << dp[mess.size()] << endl;
	return 0;
}
