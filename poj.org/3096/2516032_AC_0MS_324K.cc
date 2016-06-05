#include <iostream>
#include <string>

using namespace std;

int main()
{
	string inp;
	while ((cin >> inp), inp[0] != '*')
	{
		int i, j, k;
		for (k = 1; k < inp.size(); ++k)
		{
			for (i = 0; i + k < inp.size(); ++i)
			{
				for (j = i + 1; j + k < inp.size(); ++j)
				{
					if ((inp[i] == inp[j]) && (inp[i + k] == inp[j + k]))
					{
						break;
					}
				}
				if ((j + k) < inp.size())
				{
					break;
				}
			}
			if ((i + k) < inp.size())
			{
				break;
			}
		}
		if (k < inp.size())
		{
			cout << inp << " is NOT surprising." << endl;
		}
		else
		{
			cout << inp << " is surprising." << endl;
		}
	}
	return 0;
}
