#include <iostream>
#include <string>

using namespace std;

bool gone[32];
int length[32];
string inp;

int go(int p)
{
	if (gone[p])
	{
		return 0;
	}
	gone[p] = true;
	return (1 + go(inp[p]));
}

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int i;
		cin >> inp;
		memset(gone, false, sizeof(gone));
		memset(length, 0, sizeof(length));
		for (i = 0; i < 26; ++i)
		{
			inp[i] -= 'A';
		}
		for (i = 0; i < 26; ++i)
		{
			if (gone[i] == false)
			{
				++length[go(i)];
			}
		}
		for (i = 2; i <= 26; i += 2)
		{
			if ((length[i] & 1) != 0)
			{
				break;
			}
		}
		if (i <= 26)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}
