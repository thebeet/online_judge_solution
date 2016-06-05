#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct doll
{
	int h, w;
};

bool operator < (const doll &d1, const doll &d2)
{
	if (d1.h == d2.h)
	{
		return (d1.w > d2.w);
	}
	return (d1.h < d2.h);
}

doll ds[20010];

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 0; ti < tn; ++ti)
	{
		int i, n;
		cin >> n;
		
		for (i = 0; i < n; ++i)
		{
			scanf("%d%d", &ds[i].h, &ds[i].w);
		}
		sort(ds + 0, ds + n);
		map<int, int> hash;
		hash.clear();
		int ans(n);
		for (int i = 0; i < n; ++i)
		{
			map<int, int>::iterator it;
			++hash[ds[i].w];
			it = hash.find(ds[i].w);
			if (it != hash.begin())
			{
				map<int, int>::iterator before(it);
				--before;
				--ans;
				if (--(before->second) == 0)
				{
					hash.erase(before);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
