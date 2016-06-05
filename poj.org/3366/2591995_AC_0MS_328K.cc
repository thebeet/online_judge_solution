#include <iostream>
#include <string>

using namespace std;

string dict[32], assign[32];
string inp;

int main()
{
	int i, j, l, n;
	cin >> l >> n;
	for (i = 1; i <= l; ++i)
	{
		cin >> dict[i] >> assign[i];
	}
	for (i = 1; i <= n; ++i)
	{
		cin >> inp;
		for (j = 1; j <= l; ++j)
		{
			if (inp == dict[j])
			{
				break;
			}
		}
		if (j <= l)
		{
			inp = assign[j];
		}
		else
		{
			switch (inp[inp.size() - 1])
			{
			case 'y':
			if ((inp.size() >= 2) && 
				(	(inp[inp.size() - 2] != 'a') &&
					(inp[inp.size() - 2] != 'o') &&
					(inp[inp.size() - 2] != 'i') &&
					(inp[inp.size() - 2] != 'u') &&
					(inp[inp.size() - 2] != 'e')))
			{
				inp[inp.size() - 1] = 'i';
			}
			else
			{
				inp += "s";
				break;
			}
				//fall
			case 'o': case 's': case 'x':
				inp += "es";
				break;
			case 'h':
				if ((inp.size() >= 2) && ((inp[inp.size() - 2] == 'c') || (inp[inp.size() - 2] == 's')))
				{
					inp += "es";
					break;
				}
				//fall
			default:
				inp += "s";
			}
		}
		cout << inp << endl;
	}
	return 0;
}
