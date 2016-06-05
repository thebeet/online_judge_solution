#include <iostream>

using namespace std;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int n, m;
		if (ti > 1)
		{
			cout << endl;
		}
		cout << "Scenario #" << ti << ":" << endl;
		cin >> n >> m;
		cout << n * m << ((((n * m) & 1) == 0) ? ".00" : ".41") << endl;
	}
	return 0;
}
