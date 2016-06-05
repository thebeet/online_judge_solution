#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

map<int, int> question;

int main()
{
	int i, n, s;
	scanf("%d", &n);
	s = 0;
	for (i = 1; i <= n; ++i)
	{
		int q, a, x;
		scanf("%d%d%d", &q, &a, &x);
		if (a == 0)
		{
			s += 10;
		}
		else
		{
			s += (question[q]++) * 10;
			s += ((x == 1) ? 40 : 20);
		}
	}
	cout << s << endl;
	return 0;
}
