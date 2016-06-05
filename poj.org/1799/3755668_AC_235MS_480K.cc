#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = 3.1415926535897932;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		cout << "Scenario #" << ti << ":" << endl;
		double R;
		int n;
		cin >> R >> n;
		double alg = pi / n;
		printf("%.3lf\n", sin(alg) * R / (1 + sin(alg)));
		cout << endl;
	}
	return 0;
}
