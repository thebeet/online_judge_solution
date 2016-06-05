#include <iostream>
#include <string>

using namespace std;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		string p1, p2;
		if (p1 != p2)
		{
			int king, queen, car, ele;
			cin >> p1 >> p2;
			king = (int)max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]));
			car = ((p1[0] == p2[0]) || (p1[1] == p2[1])) ? 1 : 2;
			ele = (abs(p1[0] - p2[0]) == abs(p1[1] - p2[1])) ? 1 : 2;
			queen = min(car, ele);
			cout << king << " " << queen << " " << car << " ";
			if (((p1[0] + p1[1]) & 1) != ((p2[0] + p2[1]) & 1))
			{
				cout << "Inf" << endl;
			}
			else
			{
				cout << ele << endl;
			}
		}
		else
		{
			cout << "0 0 0 0" << endl;
		}
	}
	return 0;
}
