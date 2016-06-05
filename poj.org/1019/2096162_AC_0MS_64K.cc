#include <stdio.h>

#define INT __int64

int main()
{
	INT ti, tn, i, n, m, s, ss, sss, x, p;
	scanf("%I64d", &tn);
	for (ti = 1; ti <= tn; ti++)
	{
		scanf("%I64d", &n);
		s = 0;
		ss = 0;
		sss = 1;
		for (i = 1; ; i++)
		{
			if (i == 10) sss++;
			if (i == 100) sss++;
			if (i == 1000) sss++;
			if (i == 10000) sss++;
			if (i == 100000) sss++;
			if (i == 1000000) sss++;
			ss += sss;
			s += ss;
			if (s >= n)
			{
				s -= ss;
				break;
			}
		}
		n -= s;
		ss = 0;
		sss = 1;
		for (i = 1; ; i++)
		{
			if (i == 10) sss++;
			if (i == 100) sss++;
			if (i == 1000) sss++;
			if (i == 10000) sss++;
			if (i == 100000) sss++;
			if (i == 1000000) sss++;
			n -= sss;
			if (n <= 0)
			{
				n += sss;
				break;
			}
		}
		for (; n < sss; n++)
			i /= 10;
		printf("%I64d\n", i % 10);
	}
	return 0;
}
