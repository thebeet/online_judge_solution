#include <stdio.h>
#include <string.h>

#define MAXN 100

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
	scanf("%s", inp);
	length = strlen(inp);
	kmp_next(next, inp);
	ans = length / (length - next[length]);
	printf("%d\n", ans);	
	return 0; 
}
