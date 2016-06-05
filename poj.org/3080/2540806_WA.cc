#include <iostream>
#include <string>

using namespace std;

string dna[16];
string m;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, st, l;
		cin >> n;
		for (i = 1; i <= n; ++i)
		{
			cin >> dna[i];
		}
		for (l = 60; l >= 3; --l)
		{
			for (st = 0; st + l <= 60; ++st)
			{
				m = dna[1].substr(st, l);
				for (i = 2; i <= n; ++i)
				{
					if (dna[i].find(m) > 60)
					{
						break;
					}
				}
				if (i > n)
				{
					break;
				}
			}
			if (st + l <= 60)
			{
				break;
			}
		}
		if (l >= 3)
		{
			cout << dna[1].substr(st, l) << endl;
		}
		else
		{
			cout << "no significant commonalities" << endl;
		}
	}
	return 0;
}
