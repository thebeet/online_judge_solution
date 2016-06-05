#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = 2.0 * acos(0);

double n[128];

int main()
{
	int i, k;
	double initray;
	cin >> k;
	for (i = 1; i <= k; ++i)
	{
		cin >> n[i];
	}
	cin >> initray;
	initray = sin(initray);
	double nowray;
	for (i = 1; i <= k; ++i)
	{
		nowray = initray * n[1] / n[i];
		if (initray - 0.0000000001 > 1.0)
		{
			break;
		}
	}
	if (i <= k)
	{
		cout << "NO" << endl;
	}
	else
	{
		printf("%.6lf\n", asin(initray * n[1] / n[k]));
	}
	return 0;
}
