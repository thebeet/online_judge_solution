#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100010];
int next[100010];
int pre[100010];
int p[10010];

int ans[100010];
int ansn(0);

int main()
{
	int n;
	memset(p, -1, sizeof(p));
	memset(next, -1, sizeof(next));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int m;
		scanf("%d", &arr[i]);
		if (p[arr[i]] >= 0)
		{
			next[p[arr[i]]] = i;
		}
		p[arr[i]] = i;
	}
	memset(pre, -1, sizeof(pre));
	queue<int> q;
	int pp = 0;
	do
	{
		q.push(pp);
		pre[pp] = -2;
		pp = next[pp];
	}while (pp >= 0);
	while (pre[n - 1] == -1)
	{
		int now = q.front();
		pp = now + 1;
		do
		{
			q.push(pp);
			pre[pp] = now;
			pp = next[pp];
		}while (pp >= 0);
		q.pop();
	}
	int ppp(n - 1);
	while (ppp >= 0)
	{
		ans[++ansn] = ppp;
		ppp = pre[ppp];
	}
	for (int i = ansn; i >= 1; --i)
	{
		printf("%d ", arr[ans[i]]);
	}
	return 0;
}
