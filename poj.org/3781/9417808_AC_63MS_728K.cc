#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;
		cout << m << " ";
		int a[10];
		for (int i = 0; i < 10; ++i)
		{
			cin >> a[i];
		}
		sort(a, a + 10);
		cout << a[7] << endl;
	}
}
