#include <stdio.h>
#include <memory.h>

int beststrategy[1010][1010];
int list[1010];

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
	int ti, n;
	ti = 0;
	while (scanf("%d", &n), n > 0)
	{
		int i, j, k, sum;
		memset(beststrategy, 0, sizeof(beststrategy));
		sum = 0;
		++ti;
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &list[i]);
			sum += list[i];
		}
		for (j = 1; j <= n - 1; j += 2)
		{
			for (i = 1; i + j<= n; ++i)
			{
				 k = i + j;
				 if (list[i + 1] >= list[k])
				 {
				 	beststrategy[i][k] = MAX(beststrategy[i][k], beststrategy[i + 2][k] + list[i]);
				 }
				 else
				 {
				 	beststrategy[i][k] = MAX(beststrategy[i][k], beststrategy[i + 1][k - 1] + list[i]);
				 }
				 if (list[i] >= list[k - 1])
				 {
				 	beststrategy[i][k] = MAX(beststrategy[i][k], beststrategy[i + 1][k - 1] + list[k]);
				 }
				 else
				 {
				 	beststrategy[i][k] = MAX(beststrategy[i][k], beststrategy[i][k - 2] + list[k]);
				 }
			}
		}
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", ti, beststrategy[1][n] * 2 - sum);
	}
	return 0;
}
