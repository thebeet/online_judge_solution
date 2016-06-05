#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	cout << "PERFECTION OUTPUT" << endl;
	while ((cin >> n), n > 0)
	{
		int i, s;
		printf("%5d  ", n);
		s = 1;
		for (i = 2; i * i < n; ++i)
		{
			if ((n % i) == 0)
			{
				s += i;
				s += (n / i);
			}
		}
		if (i * i == n)
		{
			s += i;
		}
		if (n == 1)
		{
			s = 0;
		}
		if (s < n)
		{
			cout << "DEFICIENT" << endl;
		}
		if (s == n)
		{
			cout << "PERFECT" << endl;
		}
		if (s > n)
		{
			cout << "ABUNDANT" << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
