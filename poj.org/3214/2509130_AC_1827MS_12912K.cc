#include <stdio.h>
#include <string.h>

#define MAXN 1148576

int data_o[MAXN];
int data[MAXN];
int num[MAXN];

int n;
int k;
int sub;

void goafter(int i)
{
	if (i <= n)
	{
		goafter(i << 1);
		if (((i << 1) + 1) <= n)
		{
			++sub;
			goafter((i << 1) + 1);
		}
		data[++k] = data_o[i] - sub;
	}
}

int lis() // longest inc seq
{
	int i, total;
	
	memset(num, 0, sizeof(num));
	//num[0] = -(1 << 30);
	total = 0;
	
	for (i = 1; i <= n; ++i)
	{
		int lo = 0;
		int hi = total + 1;
		int mid;
		while (lo + 1 < hi)
		{
			mid = (lo + hi) >> 1;
			if (num[mid] <= data[i])
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
		if (scanf("%d", &data_o[i]) == EOF)
		{
			break;
		}
	}
	n = i - 1;
	k = 0;
	sub = 0;
	goafter(1);
	printf("%d\n", n - lis());
	return 0;
}
