#include <iostream>
#include <string>

using namespace std;

int C[32][16];

int main()
{
	int i, j;
	for (i = 0; i <= 26; ++i)
	{
		C[i][0] = 1;
		for (j = 1; j <= 10; ++j)
		{
			C[i][j] = C[i][j - 1] * (i - j + 1) / j; 
		}
	}
	string inp;
	cin >> inp;
	char pr = 'a';
	int ans = 0;
	for (i = 0; i < inp.size(); ++i)
	{
		if (i != inp.size())
		{
			ans += C[26][i];
		}
		if (pr > inp[i])
		{
			break;
		}
		for ( ; pr < inp[i]; ++pr)
		{
			ans += C[26 - (pr - 'a' + 1)][inp.size() - i - 1];
		}
		++pr;
	}
	if (i < inp.size())
	{
		ans = 0;
	}
	cout << ans << endl;
	return 0;
}
