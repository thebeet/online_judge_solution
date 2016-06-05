#include <cstdio>
#include <algorithm>

using namespace std;

int array[1024];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, k;
		scanf("%d%d", &n, &k);
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &array[i]);
		}
		for (i = 1; i <= k; ++i)
		{
			next_permutation(array, array + n);
		}
		for (i = 0; i < n - 1; ++i)
		{
			printf("%d ", array[i]);
		}
		printf("%d\n", array[i]);
	}
	return 0;
}
