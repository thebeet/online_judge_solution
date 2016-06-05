#include <iostream>
#include <string>

using namespace std;

string out[65536];

int main()
{
	int i, n;
	int ti = 0;
	while ((cin >> n), n > 0)
	{
		cout << "SET " <<++ti << endl;
		string inp;
		for (i = 1; i <= n; ++i)
		{
			if ((i & 1) == 0)
			{
				cin >> out[i >> 1];
			}
			else
			{
				cin >> inp;
				cout << inp << endl;
			}
		}
		for (i = n >> 1; i >= 1; --i)
		{
			cout << out[i] << endl;
		}
	}
	return 0;
}
