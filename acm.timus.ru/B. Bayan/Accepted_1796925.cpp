#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> visit;

int main()
{
	int i, n, ans;
	cin >> n;
	string str;
	char buf[64];
	ans = 0;
	gets(buf);
	for (i = 1; i <= n; ++i)
	{
		gets(buf);
		str = buf;
		if ((visit[str]++) > 0)
		{
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
