#include <stdio.h>

void calc(int a, int b, int &l, int &r)
{
	if (a == 1)
	{
		r += (b - 1);
		return;
	}
	if (b == 1)
	{
		l += (a - 1);
		return;
	}
	if (a > b)
	{
		l += (a / b);
		calc(a % b, b, l, r);
	}
	else
	{
		r += (b / a);
		calc(a, b % a, l, r);
	}
}

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int n, m;
		int l, r;
		l = 0; r = 0;
		scanf("%d%d", &n, &m);
		calc(n, m, l, r);
		printf("Scenario #%d:\n%d %d\n\n", ti, l, r);
	}
	return 0;
}
