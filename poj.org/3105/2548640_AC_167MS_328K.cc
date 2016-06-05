#include <iostream>

using namespace std;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, m;
		int s1, s2;
		double sum = 0;
		cin >> m;
		n = m - 1;
		for (i = 0; (n >> i) > 0; ++i)
		{
			s1 = (n >> (i + 1)) << i;
			s2 = s1;
			if (((n >> i) & 1) == 1)
			{
				s1 += 1 << i;
				s2 += (n & ((1 << (i + 1)) - 1)) + 1;
			}
			else
			{
				s1 += (n & ((1 << (i + 1)) - 1)) + 1;
			}
			sum += double(m - s1) / double (m) * double(s1) / double (m) * double(1 << (i + 1));
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}
