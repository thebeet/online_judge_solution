#include <stdio.h>
#include <memory.h>

int queue[2][100010];

int main()
{
	int ti, tn;
	
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int length;
		char toward[10];
		int i, n, ferry, t0, t1, st;
		t0 = t1 = 1;
		
		memset(queue, 0, sizeof(queue));
		
		scanf("%d%d", &ferry, &n);
		ferry *= 100;
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%d%s", &length, toward);
			
			if (toward[0] == 'l')
			{
				queue[0][++queue[0][0]] = length;
			}
			else
			{
				queue[1][++queue[1][0]] = length;
			}
		}	
		st = 0;
		for (i = 1; i <= queue[0][0]; ++i)
		{
			st += queue[0][i];
			if (st > ferry)
			{
				st = queue[0][i];
				++t0;
			}
		}
		t0 += t0 - 1;
		
		st = 0;
		for (i = 1; i <= queue[1][0]; ++i)
		{
			st += queue[1][i];
			if (st > ferry)
			{
				st = queue[1][i];
				++t1;
			}
		}
		t1 += t1;
		
		printf("%d\n", (t0 > t1) ? t0 : t1);
	}
	return 0;
} 
