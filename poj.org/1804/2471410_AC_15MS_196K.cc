#include <stdio.h>
#include <string.h>

int a[2][1010];

int mergesort(int lo, int hi)
{
	if (lo == hi)
	{
		return 0;
	}
	int i;
	int mid = (lo + hi) >> 1;
	int sum = 0;
	int *p1 = a[0];
	int l1 = mid - lo + 1;
	int *p2 = a[0] + l1 + 1;
	int *miid = p1 + l1;
	int l2 = hi - mid;
	sum += mergesort(lo, mid);
	sum += mergesort(mid + 1, hi);
	memcpy(p1, a[1] + lo, l1 * sizeof(int));
	a[0][l1] = 100000000;
	memcpy(p2, a[1] + mid + 1, l2 * sizeof(int));
	a[0][l1 + l2 + 1] = 100000000;
	for (i = lo; i <= hi; ++i)
	{
		 if (*p1 <= *p2)
		 {
		 	a[1][i] = *p1;
		 	++p1;
		 }
		 else
		 {
		 	a[1][i] = *p2;
		 	++p2;
		 	sum += miid - p1;
		 }
	}
	return sum;
}

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 1; ti <= tn; ++ti)
	{
		int n;
		scanf("%d", &n);
		
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[1][i]);
		}
		
		printf("Scenario #%d:\n%d\n\n", ti, mergesort(1, n));
	}
	return 0;
}
