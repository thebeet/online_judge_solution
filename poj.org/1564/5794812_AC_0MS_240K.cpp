/*
 * Sum_It_Up.cpp
 *
 *  Created on: Sep 1, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>

using namespace std;

int k;
int ts;
int ans[128];
int arr[128];
int num[128];
bool ansflag = false;

void dfs(const int p, const int s)
{
	if (s > ts)
	{
		return;
	}
	if (p > k)
	{
		if (s == ts)
		{
			ansflag = true;
			bool firstflag(true);
			for (int i = 0; i <= k; ++i)
			{
				for (int j = 0; j < ans[i]; ++j)
				{
					if (firstflag == false) cout << "+";
					firstflag = false;
					cout << arr[i];
				}
			}
			cout << endl;
		}
		return;
	}
	for (ans[p] = num[p]; ans[p] >= 0; --ans[p])
	{
		dfs(p + 1, s + ans[p] * arr[p]);
	}
}

int main()
{
	int n;
	while ((cin >> ts >> n), n > 0)
	{
		cout << "Sums of " << ts << ":" << endl;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		k = 0;
		num[0] = 1;
		for (int i = 1; i < n; ++i)
		{
			if (arr[i] == arr[i - 1])
			{
				++num[k];
			}
			else
			{
				arr[++k] = arr[i];
				num[k] = 1;
			}
		}
		ansflag = false;
		dfs(0, 0);
		if (ansflag == false)
		{
			cout << "NONE" << endl;
		}
	}
	return 0;
}
