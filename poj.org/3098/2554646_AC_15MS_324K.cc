#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string needall;
string needone;
string neednone;

int div(const string &query, const int pos)
{
	unsigned int i;
	needall = "";
	needone = "";
	neednone = "";
	for (i = pos; i < query.size(); ++i)
	{
		if (query[i] == '|')
		{
			return i;
		}
		if (query[i] == '-')
		{
			++i;
			neednone += query[i];
			continue;
		}
		else if (query[i] == '+')
		{
			++i;
			needall += query[i];
			continue;
		}
		else
		{
			needone += query[i];
		}
	}
	return query.size();
}

string words[128];

int main()
{
	while ((cin >> words[1]), words[1] != "#")
	{
		int i, n;
		n = 1;
		while ((cin >> words[++n]), words[n] != "*")
		{
		}
		--n;
		sort(words + 1, words + 1 + n);
		string query;
		while ((cin >> query), query != "**")
		{
			int ans = n + 1;
			int pos = 0;
			for ( ; ; )
			{
				pos = div(query, pos) + 1;
				for (i = 1; i <= n; ++i)
				{
					unsigned int j;
					int sum = 0;
					for (j = 0; j < needone.size(); ++j)
					{
						int ret;
						ret = words[i].find(needone[j]);
						if (words[i].find(needone[j]) != -1)
						{
							++sum;
						}
					}
					if (sum >= 1)
					{
						for (j = 0; j < needall.size(); ++j)
						{
							if (words[i].find(needall[j]) == -1)
							{
								break;
							}
						}
						if (j == needall.size())
						{
							for (j = 0; j < neednone.size(); ++j)
							{
								if (words[i].find(neednone[j]) != -1)
								{
									break;
								}
							}
							if (j == neednone.size())
							{
								break;
							}
						}
					}
				}
				if (i < ans)
				{
					ans = i;
				}
				if (pos >= query.size())
				{
					break;
				}
			}
			if (ans > n)
			{
				cout << "NONE" << endl;
			}
			else
			{
				cout << words[ans] << endl;
			}
		}
		cout << "$" << endl;
	}
	return 0;
}
