#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>

using namespace std;
int main()
{
	string inp;
	cin >> inp;
	int chartime[255];
	memset(chartime, 0, sizeof(chartime));
	for (unsigned int i = 0; i < inp.size(); ++i)
	{
		++chartime[inp[i]];
	}
	char ans = 'z';
	for (char c = 'a'; c < 'z'; ++c)
	{
		if (chartime[c] > chartime[ans])
		{
			ans = c;
		}
	}
	cout << ans << endl;
	return 0;
}
