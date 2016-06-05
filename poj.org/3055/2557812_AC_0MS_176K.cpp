#include <iostream>
#include <string>

using namespace std;

bool isfriends(const string &s1, const string &s2)
{
	bool use[2][64];
	int i;
	memset(use, false, sizeof(use));
	
	for (i = 0; i < s1.size(); ++i)
	{
		use[0][(int)s1[i]] = true; 
	}
	for (i = 0; i < s2.size(); ++i)
	{
		use[1][(int)s2[i]] = true; 
	}
	
	if (memcmp(use[0], use[1], 64) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int k, i, ti, tn;
	string inp[2];
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		cin >> inp[0] >> inp[1];
		if (isfriends(inp[0], inp[1]))
		{
			cout << "friends" << endl;
		}
		else
		{
			for (k = 0; k <= 1; ++k)
			{
				if ((inp[k][0] > '1') && (inp[k][1] < '9'))
				{
					--inp[k][0];
					++inp[k][1];
					if (isfriends(inp[0], inp[1]))
					{
						break;
					}
					++inp[k][0];
					--inp[k][1];
				}
				if ((inp[k][0] < '9') && (inp[k][1] > '0'))
				{
					++inp[k][0];
					--inp[k][1];
					if (isfriends(inp[0], inp[1]))
					{
						break;
					}
					--inp[k][0];
					++inp[k][1];
				}
				for (i = 2; i < inp[k].size(); ++i)
				{
					if ((inp[k][i - 1] > '0') && (inp[k][i] < '9'))
					{
						--inp[k][i - 1];
						++inp[k][i];
						if (isfriends(inp[0], inp[1]))
						{
							break;
						}
						++inp[k][i - 1];
						--inp[k][i];
					}
					if ((inp[k][i - 1] < '9') && (inp[k][i] > '0'))
					{
						++inp[k][i - 1];
						--inp[k][i];
						if (isfriends(inp[0], inp[1]))
						{
							break;
						}
						--inp[k][i - 1];
						++inp[k][i];
					}
				}
				if (i < inp[k].size())
				{
					break;
				}
			}
			if (k <= 1)
			{
				cout << "almost friends" << endl;
			}
			else
			{
				cout << "nothing" << endl;
			}
		}
	}
	return 0;
}
