#include <iostream>
#include <algorithm>

using namespace std;

int len[655360];

int main()
{
	int n, l;
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &len[i]);
	}
	sort(len + 0, len + n);
	int lo(0), hi(n - 1);
	int ans(0);
	while (lo < hi)
	{
		if (len[hi] + len[lo] <= l)
		{
			++lo;
		}
		--hi; 
		++ans;
	}
	if (lo == hi) ++ans;
	cout << ans << endl;
	return 0;
}

