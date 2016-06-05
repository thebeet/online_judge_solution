#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int m, d1, d2;
	cin >> m >> d1 >> d2;
	int total = m * d1;
	for (int i = 0; i < d2; ++i)
	{
		if (total > m)
		{
			cout << m << " ";
			total -= m;
		}
		else
		{
			cout << total << " ";
			total = 0;
		}
	}
	cout << endl;
	return 0;
}
