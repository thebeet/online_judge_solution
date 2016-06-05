#include <iostream>
#include <algorithm>

#define INT long long

using namespace std;

struct cow
{
	INT dis;
	INT des;
}cows[100010];

INT sum[100010];

bool cmp(cow c1, cow c2)
{
	return (c1.dis * c2.des > c2.dis * c1.des);
}

int main()
{
	int i, n;
	INT total = 0;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cin >> cows[i].dis >> cows[i].des;
	}
	sort(cows + 1, cows + 1 + n, cmp);
	
	sum[0] = 0;
	for (i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + cows[i].des;
	}
	
	for (i = n; i >= 1; --i)
	{
		total += sum[i - 1] * 2 * cows[i].dis;
	}
	
	cout << total << endl;
}
