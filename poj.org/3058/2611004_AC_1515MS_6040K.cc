#include <stdio.h>
#include <string.h>

const int MAXN = 1000010;

char buf[MAXN];
int tot[256];
char inp[MAXN];
int next[MAXN];
int k;

int main()
{
	setbuf(stdout, NULL);
	
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		char *ch;
		int letter;
		int i, num;
		int p;
		k = 0;
		memset(tot, 0, sizeof(tot));
		scanf("%s", buf);
		for (ch = buf; *ch != '\0'; ++ch)
		{
			num = 0;
			letter = (int)*ch;
			while ((*(ch + 1) <= '9') && (*(ch + 1) >= '0'))
			{
				++ch;
				num = num * 10 + *ch - '0';
			}
			if (num == 0)
			{
				inp[++k] = letter;
				++tot[letter];
			}
			else
			{
				memset(inp + k + 1, letter, num);
				tot[letter] += num;
				k += num;
			}
		}
		tot[(int)'.'] = 0;
		tot[(int)'Z'] = k - tot[(int)'Z'];
		for (letter = 'Y'; letter >= 'A'; --letter)
		{
			tot[letter] = tot[letter + 1] - tot[letter];
		}
		for (i = 1; i <= k; ++i)
		{
			next[++tot[(int)inp[i]]] = i;
		}
		p = next[next[1]];
		for (i = 1; i < k; ++i)
		{
			printf("%c", inp[p]);
			p = next[p];
		}
		printf(".\n");
	}
	return 0;
}
