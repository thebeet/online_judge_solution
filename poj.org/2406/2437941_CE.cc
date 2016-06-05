#include <stdio.h>
#include <string.h>

#define MAXN 1000100

int next[MAXN];
char inp[MAXN];

void kmp_next(int *next, char *s)
{
	int i = 0;
	int j = -1;
	next[0] = -1;
	while (s[i] != '\0')
	{
		while ((j >= 0) && (s[i] != s[j]))
		{
			j = next[j];
		}
		next[++i] = ++j;
	}
	return;
}

int main()
{
	int length, ans;
	memset(next, 0, sizeof(next));
	memset(inp, 0, sizeof(inp));
	
	while (scanf("%s", inp), inp[0] != '.')
	{
		length = strlen(inp);
		kmp_next(next, inp);
		if ((length % (length - next[length]) == 0)
		{
			ans = length / (length - next[length]);
		}
		else
		{
			ans = 1;
		}
		printf("%d\n", ans);	
	}
	return 0; 
}
