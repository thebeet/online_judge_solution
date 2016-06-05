#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		string inp;
		cin >> inp;
		for (unsigned int i = 0; i < inp.size(); )
		{
			int m(1);
			int now = i;
			while (inp[++i] == inp[now])
			{
				++m;
			}
			cout << m << inp[now];
		}
		cout << endl;
	}
	return 0;
}
