#include <stdio.h>
#include <memory.h>

#define INT unsigned int

INT ss[47000];
bool sss[1000010];

int main()
{
	INT i, j, f, t;
	memset(ss, 0, sizeof(ss));
	for (i = 2; i <= 50340; ++i)
	{
		if (ss[i] == 0)
		{
			ss[++ss[0]] = i;
			j = i * i;
			while (j <= 50340)
			{
				ss[j] = 1;
				j += i;
			}
		}
	}
	
	while (scanf("%u%u", &f, &t) != EOF)
	{
		INT j;
		INT ansp1, dis1;
		INT ansp2, dis2;
		INT pr;
		memset(sss, false, sizeof(sss));
		ansp1 = 0; dis1 = 100000000;
		ansp2 = 0; dis2 = 0;
		
		for (i = 1; (i <= ss[0]) && (ss[i] * ss[i] <= t); ++i)
		{
			j = ((f - 1) / ss[i] + 1) * ss[i];
			if (j == ss[i])
			{
				j += ss[i];
			}
			while (j <= t)
			{
				sss[j - f] = true;
				j += ss[i];
			}
		}
		pr = 0;
		for (i = 0; i <= (t - f); ++i)
		{
			if (sss[i] == false)
			{
				pr = i;
				break;
			}
		}
		if (i > (t - f))
		{
			printf("There are no adjacent primes.\n");
		}
		else
		{
			for (++i; i <= (t - f); ++i)
			{
				if (sss[i] == false)
				{
					if ((i - pr) < dis1)
					{
						dis1 = i - pr;
						ansp1 = i;
					}
					if ((i - pr) > dis2)
					{
						dis2 = i - pr;
						ansp2 = i;
					}
					pr = i;
				}
			}
			if (dis2 == 0)
			{
				printf("There are no adjacent primes.\n");
			}
			else
			{
				printf("%u,%u are closest, %u,%u are most distant.\n", ansp1 + f - dis1, ansp1 + f, ansp2 + f - dis2, ansp2 + f);
			}
		}
	}
	return 0;
}			
