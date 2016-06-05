#include <stdio.h>
#include <string.h>

#define L 75

char 	inp_C[10];
char	data[1001100][100];

void out_space(long m)
{
	long i;
	for (i = 1; i <= m; i++)
	{
		printf(" ");
	}
}

void out_word(long f, long t, long k)
{
	long i, s;
	for (i = f; i < t; i++)
	{
		printf("%s ", data[i]);
		s = (k + t - i - 1) / (t - i);
		out_space(s);
		k -= s;
	}
	printf("%s", data[t]);
}

int main()
{
	long 	n, pr, sp, l;
	memset(inp_C, 0, sizeof(inp_C));
	memset(data, 0, sizeof(data));
	scanf("%s", inp_C);
	n = 0;
	pr = 1;
	l = -1;
	while (scanf("%s", data[n + 1]) != EOF)
	{
		n++;
		l += (strlen(data[n]) + 1);
		if (l > L)
		{
			l -= (strlen(data[n]) + 1);
			sp = L - l;
			switch (inp_C[0])
			{
				case 'L':
					{
						 out_word(pr, n - 1, 0);
						 //out_space(sp);
						 break;
					}
				case 'R':
					{
						 out_space(sp);
						 out_word(pr, n - 1, 0);
						 break;
					}
				case 'C':
					{
						 out_space(sp / 2);
						 out_word(pr, n - 1, 0);
						 //out_space(sp - (sp / 2));
						 break;
					}
				case 'J':
					{
						 out_word(pr, n - 1, sp);
						 break;
					}
			}
			printf("\n");
			pr = n;
			l = strlen(data[n]);
		}
	}
	sp = L - l;
	switch (inp_C[0])
	{
		case 'L':
			{
				 out_word(pr, n, 0);
				 //out_space(sp);
				 break;
			}
		case 'R':
			{
				 out_space(sp);
				 out_word(pr, n, 0);
				 break;
			}
		case 'C':
			{
				 out_space(sp / 2);
				 out_word(pr, n, 0);
				 //out_space(sp - (sp / 2));
				 break;
			}
		case 'J':
			{
				 out_word(pr, n, 0);
				 break;
			}
	}
	printf("\n");
	return 0;
}
