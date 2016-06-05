#include <iostream>
#include <string>

using namespace std;

char usage[256];

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		unsigned int i, st, ans;
		string s;
		st = 0;
		ans = 0;
		cin >> s;
		memset(usage, 0, sizeof(usage));
		for (i = 0; i < s.size(); ++i)
		{
			if (usage[s[i]] == 0)
			{
				if (st == n)
				{
					++ans;
					usage[s[i]] = 2;
				}
				else
				{
					++st;
					usage[s[i]] = 1;
				}
			}
			else
			{
				if (usage[s[i]] == 1)
				{
					--st;
				}
			}
		}
		if (ans == 0)
		{
			 cout << "All customers tanned successfully." << endl;
		}
		else
		{
			cout << ans << " customer(s) walked away." << endl;
		}
	}
	return 0;
}
