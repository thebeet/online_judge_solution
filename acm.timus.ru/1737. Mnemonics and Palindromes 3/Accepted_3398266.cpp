#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "a" << endl << "b" << endl << "c" << endl;
	}
	else if (n > 100000 / 6)
	{
		cout << "TOO LONG" << endl;
	}
	else
	{
		char a[4] = "abc";
		do
		{
			for (int i = 0; i < n; ++i)
			{
				cout << a[i % 3];
			}
			cout << endl;
		}while (next_permutation(a, a + 3));
	}
	return 0;
}
