#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		bool ans;
		ans = false;
		while (n > 1)
		{
			if (ans == false)
			{
				ans = true;
				n = (n - 1) / 9 + 1;
			}
			else
			{
				ans = false;
				n = (n - 1) / 2 + 1;
			}
		}
		if (ans)
		{
			printf("Stan wins.\n");
		}
		else
		{
			printf("Ollie wins.\n");
		}
	}
	return 0;
}
