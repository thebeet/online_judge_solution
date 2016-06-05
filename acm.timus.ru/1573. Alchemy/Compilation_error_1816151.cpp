#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int B, R, Y;
	int i, k, s;
	cin >> B >> R >> Y;
	cin >> k;
	s = 1;
	for (i = 1; i <= k; ++i)
	{
		string color;
		cin >> color;
		if (color == "Red")
		{
			s *= R;
		}
		else if (color == "Blue")
		{
			s *= B;
		}
		else
		{
			s *= Y;
		}
	}
	cout << s << endl;
	return 0;
}
