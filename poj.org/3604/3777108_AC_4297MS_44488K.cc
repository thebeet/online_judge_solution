#include <iostream>
#include <algorithm>

using namespace std;

int ans[5000010];
int fact[5000010];
bool prime[5000010];

int main()
{
	for (int i = 1; i <= 5000000; ++i)
	{
		fact[i] = 1;
		ans[i] = 1;
	}
	memset(prime, true, sizeof(prime));
	for (int i = 2; i < 5000000; ++i)
	{
		if (prime[i])
		{
			for (int j = 1, p = i; p <= 5000000; ++j, p += i) 
			{
				fact[p] += fact[j];
				//ans[p] += fact[j];
				prime[p] = false;
			}
		}
	}
	for (int i = 2; i < 5000000; ++i)
	{
		for (int p = i; p <= 5000000; p += i) 
		{
			ans[p] += fact[i];
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		int m;
		scanf("%d", &m);
		cout << ans[m] * ans[m] << endl;
	}
	return 0;
}
