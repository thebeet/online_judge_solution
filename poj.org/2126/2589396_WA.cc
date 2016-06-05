#include <iostream>

using namespace std;

int main()
{
	int n, a, b, c;
	cin >> n;
	if ((n <= 1) || ((n == 2) && ((cin >> a >> b >> c), (b * b > ((a + c) << 2)))))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
