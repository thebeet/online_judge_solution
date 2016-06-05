#include <stdio.h>
#include <string.h>

#define MAXN 1800010

int data_o[MAXN];
int data[MAXN];
int num[MAXN];
int wei[MAXN];

int n;
int k;

void goafter(int i)
{
	if (i <= n)
	{
		goafter(i << 1);
		goafter((i << 1) + 1);
		if ((data[k] != data_o[i]) || ((i << 1) > n))
		{
			data[++k] = data_o[i];
			wei[k] = 1;
		}
		else
		{
			++wei[k];
		} 
	}
}

int lds() // large inc seq
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
			if (num[mid] < data[i])
			{
				lo = mid;
			}
			else
			{
				hi = mid;
			}
		}
		for (int j = 1; j <= wei[i]; ++j)
		{
			num[lo + j] = data[i];
		}
		if ((lo + wei[i]) > total)
		{
			total = lo + wei[i];
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
	goafter(1);
	printf("%d\n", n - lds());
	return 0;
}
