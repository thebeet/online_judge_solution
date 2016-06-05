#include <iostream>

using namespace std;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int sum;
		cin >> sum;
		cout << ti << " ";
		cout << (sum / 25) << " QUARTER(S), ";
		sum %= 25;
		cout << (sum / 10) << " DIME(S), ";
		sum %= 10;
		cout << (sum / 5) << " NICKEL(S), ";
		sum %= 5;
		cout << sum << " PENNY(S)" << endl;
	}
	return 0;
}
