#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int array[1024];

int gcd(int a, int b)
{
	int r;
	if (a < b)
	{
		r = b;
		b = a;
		a = b;
	}
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		int i;
		int sum = 0;
		int l = 0;
		for (i = 1; i <= n; ++i)
		{
			cin >> array[i];
			for (int j = 1; j < i; ++j)
			{
				if (gcd(array[i], array[j]) == 1)
				{
					++sum;
				}
				++l;
			}
		}
		if (sum == 0)
		{
			cout << "No estimate for this data set." << endl;
		}
		else
		{
			printf("%.6lf\n", sqrt(6.0 * (double)l / (double)sum));
		}
		
	}
	return 0;
}
