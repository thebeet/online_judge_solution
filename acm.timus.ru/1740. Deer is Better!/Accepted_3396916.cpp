#include <iostream>
using namespace std;
int main()
{
	int l, k, h;
	cin >> l >> k >> h;
	double t = l / k;
	if (l % k == 0)
	{
		cout << t * h << " " << t * h << endl;
	}
	else
	{
		cout << t * h << " " << (t + 1.0) * h << endl;
	}
	return 0;
}
