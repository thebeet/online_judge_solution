#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << "Gnomes:" << endl;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (((a < b) && (b < c)) ||
		    ((a > b) && (b > c)))
		{
			cout << "Ordered" << endl;
		}
		else
		{
			cout << "Unordered" << endl;
		}
	}
	return 0;
}
