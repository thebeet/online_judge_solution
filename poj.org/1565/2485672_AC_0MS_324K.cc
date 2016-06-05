#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string inp;
	int ans, t;
	while (cin >> inp)
	{
		if (inp[0] == '0')
		{
			break;
		}
		ans = 0;
		t = 0;
		for (int i = inp.size() - 1; i >= 0; --i)
		{
			t = (t << 1) + 1;
			ans += t * (inp[i] - '0');
		}
		cout << ans << endl;
	}
	return 0;
}
