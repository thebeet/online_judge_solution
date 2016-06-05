#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	char a[128], b[128];
	scanf("%s%s", a, b);
	int ans(0);
	for (int i = 0; i < strlen(a); ++i)
	{
		for (int j = 0; j < strlen(b); ++j)
		{
			ans += (int)(a[i] - '0') * (int)(b[j] - '0');
		}
	}
	cout << ans << endl;
	return 0;
}
