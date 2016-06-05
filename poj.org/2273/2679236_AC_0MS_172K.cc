#include <stdio.h>
#include <string.h>

int main()
{
	int n, m;
	while (scanf("%*c%d%*c%d%*c", &n, &m), n > 0)
	{
		--m;
		char buf[32];
		int nn = 0;
		do
		{
			buf[nn++] = (char)(m % 26 + 'A');
			m = m / 26 - 1;
		}while (m >= 0);
		buf[nn] = '\0';
		strrev(buf);
		printf("%s%d\n", buf, n);
	}
	return 0;
}
