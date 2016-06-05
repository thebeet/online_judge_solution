#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n1, c1, n2, t, c2, n3;
	cin >> n1 >> c1 >> n2 >> t >> c2 >> n3;
	int i, n;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		int mm, ss;
		scanf("%d:%d", &mm, &ss);
		if ((mm == 0) && (ss <= 6))
		{
			continue;
		}
		if (ss > 0) ++mm;
		n1 += c1 * mm;
		if (t >= mm)
		{
			t -= mm;
		}
		else
		{
			mm -= t;
			t = 0;
			n2 += c2 * mm;
		}
	}
	cout << "Basic:     " << n1 << endl;
	cout << "Combined:  " << n2 << endl;
	cout << "Unlimited: " << n3 << endl;
	return 0;
}
