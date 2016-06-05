#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 1; ti <= tn; ++ti)
	{
		unsigned int i;
		string reqs;
		string ups, downs;
		cin >> reqs >> ups >> downs;
		unsigned int nowp(0);
		for (i = 0; (i < ups.size()); ++i)
		{
			if ((ups[i] == '*') || (reqs[nowp] == ups[i]) ||(reqs[nowp] == downs[i]))
			{
				++nowp;
				if (nowp == reqs.size())
				{
					break;
				}
			}
		}
		cout << ((nowp == reqs.size()) ? "win" : "lose") << endl;
	}
	return 0;
}
