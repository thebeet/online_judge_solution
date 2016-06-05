#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
string assign[256];
string inp;
string inp_t;

int ans[1024];

void init()
{
	char buf[1024];
	for (int i = 1; i <= 26; ++i)
	{
		sprintf(buf, "%d", i);
		assign[i + 'A' - 1] = buf;
	}
}

int main()
{
	init();
	while ((cin >> inp_t), inp_t != "0")
	{
		int i, j;
		
		memset(ans, 0, sizeof(ans));
		ans[0] = 1;
		for (i = 1; i <= inp_t.size(); ++i)
		{
			for (j = 'A'; j <= 'Z'; ++j)
			{
				if (assign[j].size() <= i)
				{
					if (assign[j] == inp_t.substr(i - assign[j].size(), assign[j].size()))
					{
						ans[i] += ans[i - assign[j].size()];
					}
				}
			}
		}
		cout << ans[inp_t.size()] << endl;
	}
	return 0;
}
