#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int usage[2][256];

int main()
{
	char buf[2][1024];
	while (gets(buf[0]) != NULL)
	{
		gets(buf[1]);
		memset(usage, 0, sizeof(usage));
		int k, i;
		for (k = 0; k <= 1; ++k)
		{
			for (i = 0; i < strlen(buf[k]); ++i)
			{
				++usage[k][(int)buf[k][i]];
			}
		}
		for (char i = 'a'; i <= 'z'; ++i)
		{
			cout << string(min(usage[0][(int)i], usage[1][(int)i]), i);
		}
		cout << endl;
	}
	return 0;
}
