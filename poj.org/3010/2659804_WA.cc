#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int MAXN = 1000010;

struct node
{
	int sum;
	int mul;
	int child;
	int bro;
	char data;
}nodes[1024];

char inp[1024];
int stack[1024];
int sum[1024];

char findchar(int p, int rest)
{
	while (nodes[p].child != 0)
	{
		while ((rest <= nodes[p].sum) && (nodes[p].child != 0))
		{
			p = nodes[p].child;
		}
		while (rest > nodes[p].sum)
		{
			rest -= nodes[p].sum;
			p = nodes[p].bro;
		}
	}
	return nodes[p].data;
}

int main()
{
	int k;
	while (scanf("%s%d", inp, &k), inp[0] != '0')
	{
		char *i;
		
		memset(nodes, 0, sizeof(nodes));
		memset(sum, 0, sizeof(sum));
		memset(stack, 0, sizeof(stack));
		int now = 1;
		stack[0] = 0;
		sum[0] = 0;
		nodes[0].child = 1;
		nodes[0].bro = 0;
		nodes[0].data = '#';
		nodes[0].mul = 1;
		for (i = inp; *i != '\0'; ++i)
		{
			if (*i == ')')
			{
				nodes[stack[stack[0]]].bro = ((*(i + 1) != ')') ? now : 0);
				nodes[stack[stack[0]]].sum = sum[stack[0]] * nodes[stack[stack[0]]].mul;
				if (nodes[stack[stack[0]]].sum > MAXN)
				{
					nodes[stack[stack[0]]].sum = MAXN;
				}
				sum[stack[0] - 1] += nodes[stack[stack[0]]].sum;
				--stack[0];
				if (sum[stack[0]] > MAXN)
				{
					sum[stack[0]] = MAXN;
				}
			}
			else
			{
				nodes[now].mul = 0;
				while (isdigit(*i))
				{
					(nodes[now].mul *= 10) += *(i++) - '0';
				}
				if (nodes[now].mul == 0)
				{
					nodes[now].mul = 1;
				}
				if (isalpha(*i))
				{
					nodes[now].data = *i;
					nodes[now].child = 0;
					nodes[now].bro = ((*(i + 1) != ')') ? now + 1 : 0);
					nodes[now].sum = nodes[now].mul;
					sum[stack[0]] += nodes[now].sum;
					++now;
				}
				else
				{
					stack[++stack[0]] = now;
					sum[stack[0]] = 0;
					nodes[now].child = now + 1;
					nodes[now].data = '#';
					++now;
				}
			}
		}
		nodes[0].sum = sum[0];
		/*for (int i = 0; i <= now; ++i)
		{
			fprintf(stderr, "id:%d sum=%d mul=%d child=%d bro=%d data=%c\n", i, nodes[i].sum, nodes[i].mul, nodes[i].child, nodes[i].bro, nodes[i].data);
		}*/
		
		++k;
		if (k > nodes[0].sum)
		{
			printf("0\n");
		}
		else
		{
			printf("%c\n", findchar(0, k));
		}
	}
	return 0;
}
