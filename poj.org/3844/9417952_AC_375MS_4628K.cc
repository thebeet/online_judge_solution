
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		int d, n;
		cin >> d >> n;
		int md[d];
		memset(md, 0, sizeof(md));
		md[0] = 1;
		int s = 0;
		long long result = 0;
		for (int i = 0; i < n; ++i)
		{
			int a;
			scanf("%d", &a);
			(s += a) %= d;
			result += md[s];
			++md[s];
		}
		cout << result << endl;
	}
}
