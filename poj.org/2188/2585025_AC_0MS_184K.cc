#include <stdio.h>
#include <string.h>

int p[2][1024];
int wires[2][1024];

int mergesort(int lo, int hi)
{
	if (lo == hi)
	{
		return 0;
	}
	int i;
	int mid = (lo + hi) >> 1;
	int sum = 0;
	int *p1 = wires[0];
	int l1 = mid - lo + 1;
	int *p2 = wires[0] + l1 + 1;
	int *miid = p1 + l1;
	int l2 = hi - mid;
	sum += mergesort(lo, mid);
	sum += mergesort(mid + 1, hi);
	memcpy(p1, wires[1] + lo, l1 * sizeof(int));
	wires[0][l1] = 100000000;
	memcpy(p2, wires[1] + mid + 1, l2 * sizeof(int));
	wires[0][l1 + l2 + 1] = 100000000;
	for (i = lo; i <= hi; ++i)
	{
		 if (*p1 <= *p2)
		 {
		 	wires[1][i] = *p1;
		 	++p1;
		 }
		 else
		 {
		 	wires[1][i] = *p2;
		 	++p2;
		 	sum += miid - p1;
		 }
	}
	return sum;
}


int main()
{
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		int a;
		scanf("%d%d", &a, &p[1][i]);
		p[0][a] = i;
	}
	for (i = 1; i <= n; ++i)
	{
		wires[1][i] = p[0][p[1][i]];
	}
	printf("%d\n", mergesort(1, n));
	return 0;
}
