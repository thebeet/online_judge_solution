#include <iostream>

using namespace std;

int inp[25];
int b_inp[25];

int main()
{
	int i, change;
	int ans = 200;
	for (i = 1; i <= 20; ++i)
	{
		cin >> inp[i];
	}
	memcpy(b_inp, inp, sizeof(inp));
	change = 0;
	for (i = 1; i <= 19; ++i)
	{
		if (inp[i] == 1)
		{
			inp[i + 1] ^= 1;
			inp[i + 2] ^= 1;
			++change;
		}
	}
	if (inp[20] == 0)
	{
		ans = change;
	}
	
	memcpy(inp, b_inp, sizeof(inp));
	change = 1;
	inp[1] ^= 1;
	inp[2] ^= 1;
	for (i = 1; i <= 19; ++i)
	{
		if (inp[i] == 1)
		{
			inp[i + 1] ^= 1;
			inp[i + 2] ^= 1;
			++change;
		}
	}
	if ((inp[20] == 0) && (ans > change))
	{
		ans = change;
	}
	cout << ans << endl;
	return 0;
}
