#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int value(int d)
{
	int s(0);
	while (d > 0)
	{
		s += d % 10;
		d /= 10;
	}
	return s;
}

int main()
{
	int n;
	cin >> n;
	vector<int> ans;
	int k = 99999;
	while (n > 0)
	{
		int b = value(k);
		if (b <= n)
		{
			n -= b;
			ans.push_back(k);
		}
		--k;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
