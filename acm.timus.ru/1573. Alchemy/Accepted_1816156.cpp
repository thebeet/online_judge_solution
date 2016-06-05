#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int iB, iR, iY;
	int i, k, s;
	cin >> iB >> iR >> iY;
	cin >> k;
	s = 1;
	for (i = 1; i <= k; ++i)
	{
		string color;
		cin >> color;
		if (color == "Red")
		{
			s *= iR;
		}
		else if (color == "Blue")
		{
			s *= iB;
		}
		else
		{
			s *= iY;
		}
	}
	cout << s << endl;
	return 0;
}
