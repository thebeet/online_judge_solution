#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const string expect = "Sandro";

int costforchange(char c1, char c2)
{
	int c = 0;
	if ((c1 <= 'Z') ^ (c2 <= 'Z'))
	{
		c += 5;
	}
	if (c1 >= 'a') c1 += 'A' - 'a';
	if (c2 >= 'a') c2 += 'A' - 'a';
	if (c1 != c2) c += 5;
	return c;
}

int main()
{
	string inp;
	cin >> inp;
	int mincost = 1000000;
	for (int i = 0; i < inp.size(); ++i)
	{
		int cost = 0;
		for (int j = 0; j < expect.size(); ++j)
		{
			if (i + j >= inp.size())
			{
				cost = 10000000;
				break;
			}
			cost += costforchange(inp[i + j], expect[j]);
		}
		mincost = min(mincost, cost);
	}
	cout << mincost << endl;
	return 0;
}
