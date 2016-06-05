#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

string name[1024];

int main()
{
	int i, j, n, ans;
	cin >> n;
	for (i = 0; i < (1 << n); ++i)
	{
		string tmp;
		cin >> tmp >> name[i];
	}
	sort(name, name + (1 << n));
	int mx = 0;
	int st = 0;
	for (i = 1; i < (1 << n); ++i)
	{
		if (name[i] != name[i - 1])
		{
			st = 1;
		}
		else
		{
			++st;
		}
		mx = max(mx, st);
	}
	//cout << mx << endl;
	for (ans = 1; ans <= n; ++ans)
	{
		if (mx > (1 << (n - ans)))
		{
			break;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
