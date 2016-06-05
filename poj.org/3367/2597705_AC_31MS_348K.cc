#include <stdio.h>
#include <string.h>

const int size = 10010;

struct num
{
	int d1, d2;
}nums[size];

char inp[size];
char out[size];
int stack[size];
int queue[size];
int k;

void bfs(int p)
{
	queue[0] = 1;
	queue[1] = p;
	for (int i = 1; i <= queue[0]; ++i)
	{
		out[--k] = inp[queue[i]];
		if (inp[queue[i]] <= 'Z')
		{
			queue[++queue[0]] = nums[queue[i]].d1; 
			queue[++queue[0]] = nums[queue[i]].d2;
		}
	}
}

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		memset(nums, 0, sizeof(nums));
		memset(inp, 0, sizeof(inp));
		memset(stack, 0, sizeof(stack));
		memset(out, 0, sizeof(out));
		
		int i, len;
		scanf("%s", inp);
		len = strlen(inp);
		for (i = 0; i < len; ++i)
		{
			if (inp[i] <= 'Z')
			{
				nums[i].d1 = stack[stack[0] - 1];
				nums[i].d2 = stack[stack[0]];
				stack[0] -= 2;
			}
			stack[++stack[0]] = i;
		}
		k = len;
		for (i = stack[0]; i >= 1; --i)
		{
			bfs(stack[i]);
		}
		printf("%s\n", out);
	}
	return 0;
}
