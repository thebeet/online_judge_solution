#include <stdio.h>
#include <memory.h>

bool map[255][255];

int main()
{
	long i, n;
	char inp[10];
	scanf("%ld", &n);
	memset(map, false, sizeof(map));
	for (i = 1; i <= n; i++)
	{
		scanf("%s", inp);
		map[inp[0]][inp[1]] = true;
	}
	scanf("%s", inp);
	for (i = 1; i <= 255; i++)
	{
		if (map[inp[0]][i])
		{
			printf("%c%c\n", inp[0], (char)i);
		}
	}
	return 0;
}
