#include <iostream>

using namespace std;

int inp[1024];
int stack[1024];

int main()
{
	int ti, n;
	ti = 0;
	while ((cin >> n), n > 0)
	{
		++ti;
		if (ti > 1)
		{
			cout << endl;
		}
		while ((cin >> inp[1]), inp[1] > 0)
		{
			int i, wait;
			stack[0] = 0;
			wait = 0;
			for (i = 2; i <= n; ++i)
			{
				cin >> inp[i];
			}
			for (i = 1; i <= n; ++i)
			{
				while (inp[i] != stack[stack[0]])
				{
					stack[++stack[0]] = ++wait;
					if (wait > n)
					{
						break;
					}
				}
				if (wait > n)
				{
					break;
				}
				--stack[0];
			}
			if (i <= n)
			{
				cout << "No" << endl;
			}
			else
			{
				cout << "Yes" << endl;
			}
		}
	}
	return 0;
}
