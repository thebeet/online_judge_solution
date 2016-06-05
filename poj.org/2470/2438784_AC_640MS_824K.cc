#include <stdio.h>
#include <memory.h>

int q[100010][2];

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		int i;
		memset(q, 0, sizeof(q));
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &q[i][0]);
			q[q[i][0]][1] = i;
		}
		for (i = 1; i <= n; ++i)
		{
			if (q[i][0] != q[i][1])
			{
				break;
			}
		}
		if (i <= n)
		{
			printf("not ambiguous\n");
		}
		else
		{
			printf("ambiguous\n");
		}
	}
	return 0;
}			 
