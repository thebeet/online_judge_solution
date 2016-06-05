#include <stdio.h>
#include <memory.h>

int c[20];
int a[20];
bool u[20];
int n, sum;

bool make_seq(int h, int s)
{
	if (s > sum) return false;
	if (h == n)
	{
		if (s == sum) return true;
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			if (u[i])
			{
				a[h] = i;
				u[i] = false;
				if (make_seq(h + 1, s + c[h] * i)) return true;
				u[i] = true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &sum);
	memset(u, true, sizeof(u));
	c[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		c[i] = c[i - 1] * (n  - i) / i;
	}
	if (make_seq(0, 0))
	{
		for (int i = 0; i < n - 1; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("%d\n", a[n - 1]);
	}
	return 0;
}
