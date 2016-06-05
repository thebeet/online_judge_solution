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
		}
		else if (query[i] == '+')
		{
			++i;
			needall += query[i];
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
			unsigned int pos = 0;
			for ( ; ; )
			{
				pos = div(query, pos) + 1;
				for (i = 1; i <= n; ++i)
				{
					unsigned int j;
					int sum = 0;
					for (j = 0; j < needone.size(); ++j)
					{
						if (words[i].find(needone[j]) < words[i].size())
						{
							++sum;
						}
					}
					if (sum >= 1)
					{
						for (j = 0; j < needall.size(); ++j)
						{
							if (words[i].find(needall[j]) >= words[i].size())
							{
								break;
							}
						}
						if (j == needall.size())
						{
							for (j = 0; j < neednone.size(); ++j)
							{
								if (words[i].find(neednone[j]) < words[i].size())
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
				if ((i <= n) || (pos >= query.size()))
				{
					break;
				}
			}
			if (i > n)
			{
				cout << "NONE" << endl;
			}
			else
			{
				cout << words[i] << endl;
			}
		}
	}
	return 0;
}
