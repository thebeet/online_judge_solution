#include <iostream>
#include <string>

using namespace std;

int main()
{
	string inp;
	while ((cin >> inp), inp != "#")
	{
		int ans = 0;
		int i, j;
		for (i = 0; i < inp.size(); ++i)
		{
			if (inp[i] == '.')
			{
				ans += 2;
			}
			if (inp[i] == '/')
			{
				for (j = i - 1; j >= 0; --j)
				{
					if (inp[j] == '.')
					{
						j = -1;
						break;
					}
					if (inp[j] != '_')
					{
						break;
					}
				}
				if (j < 0)
				{
					ans += 2;
				}
			}
			if (inp[i] == '\\')
			{
				for (j = i + 1; j < inp.size(); ++j)
				{
					if (inp[j] == '.')
					{
						j = inp.size();
						break;
					}
					if (inp[j] != '_')
					{
						break;
					}
				}
				if (j == inp.size())
				{
					ans += 2;
				}
			}
			if (inp[i] == '|')
			{
				for (j = i - 1; j >= 0; --j)
				{
					if (inp[j] == '.')
					{
						j = -1;
						break;
					}
					if (inp[j] != '_')
					{
						break;
					}
				}
				if (j < 0)
				{
					ans += 1;
				}
				for (j = i + 1; j < inp.size(); ++j)
				{
					if (inp[j] == '.')
					{
						j = inp.size();
						break;
					}
					if (inp[j] != '_')
					{
						break;
					}
				}
				if (j == inp.size())
				{
					ans += 1;
				}
			}
		}
		ans = ans * 50 / inp.size();
		cout << ans << endl;
	}
	return 0;
}
