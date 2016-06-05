#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	double d;
	while (cin >> n >> d)
	{
		cout << (int)(pow(d, 1.0 / (double)n) + 0.001) << endl;
	}
	return 0;
}
