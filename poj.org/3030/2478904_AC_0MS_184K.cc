#include <stdio.h>

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (b == (a + c))
		{
			printf("does not matter\n");
		}
		if (b > (a + c))
		{
			printf("advertise\n");
		}
		if (b < (a + c))
		{
			printf("do not advertise\n");
		}
	}
	return 0;
}
