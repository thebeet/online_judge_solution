#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

double array[10010];

int main()
{
	int i, n;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cin >> array[i];
	}
	sort(array + 1, array + 1 + n);
	for (i = n; i >= 2; --i)
	{
		array[i - 1] = 2.0 * sqrt(array[i] * array[i - 1]);
	}
	printf("%.3lf\n", array[1]);
	return 0;
}
