#include <stdio.h>
#include <string.h>

#define BLOCKSIZE 1000

char mystr[1010][3010];
int total[1010];
int ttotal;
char inp[1001010];

int main()
{
	int i, j, k, l, n, m;
	scanf("%s", inp);
	k = 1;
	l = strlen(inp);
	for (i = 0; i < l; i += BLOCKSIZE, ++k)
	{
		memcpy(mystr[k] + 1, inp + i, BLOCKSIZE);
		total[k] = BLOCKSIZE;
	}
	total[--k] = l - i + BLOCKSIZE;
	ttotal = l;
	
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%s", inp);
		if (inp[0] == 'Q')
		{
			scanf("%d", &m);
			for (j = 1; ; ++j)
			{
				if (m <= total[j])
				{
					break;
				}
				else
				{
					m -= total[j];
				}
			}
			printf("%c\n", mystr[j][m]);
		}
		else
		{
			scanf("%s%d", inp, &m);
			if (m > ttotal)
			{
				++ttotal;
				mystr[k][++total[k]] = inp[0];
			}
			else
			{
				for (j = 1; ; ++j)
				{
					if (m <= total[j])
					{
						break;
					}
					else
					{
						m -= total[j];
					}
				}
				++ttotal;
				++total[j];
				memmove(mystr[j] + m + 1, mystr[j] + m, total[j] - m);
				mystr[j][m] = inp[0];
			}
		}
	}
	return 0;
}
