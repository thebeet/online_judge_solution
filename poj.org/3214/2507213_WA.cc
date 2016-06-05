#include <stdio.h>
#include <string.h>

#define MAXN 1800010
#define PRE 0.000001

int data_o[MAXN];
double data[MAXN];
double num[MAXN];

int n;
int k;

void goafter(int i, int h)
{
	if (i <= n)
	{
		goafter(i << 1, h + 1);
		goafter((i << 1) + 1, h + 1);
		data[++k] = data_o[i] + 0.1/(double)h;
	}
}

int lis() // large inc seq
{
	int i, total;
	
	memset(num, 0, sizeof(num));
	num[0] = 0;
	total = 0;
	
	for (i = 1; i <= k; ++i)
	{
		int lo = 0;
		int hi = total + 1;
		int mid;
		while (lo + 1 < hi)
		{
			mid = (lo + hi) >> 1;
			if (num[mid] + PRE < data[i])
			{
				lo = mid;
			}
			else
			{
				hi = mid;
			}
		}
		num[hi] = data[i];
		if (hi > total)
		{
			total = hi;
		}
	}
	return total;
}

int main()
{
	int i;
	scanf("%d", &n);
	n = (1 << n) - 1;
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &data_o[i]);
	}
	k = 0;
	goafter(1, 1);
	printf("%d\n", n - lis());
	return 0;
}
