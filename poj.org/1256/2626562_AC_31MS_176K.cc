#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char inp[16];

bool cmp(char c1, char c2)
{
	return ((c1 > 'Z') ? ((c1 - 'a') << 1) | 1 : ((c1 - 'A') << 1)) < ((c2 > 'Z') ? ((c2 - 'a') << 1) | 1 : ((c2 - 'A') << 1));
}

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int n;
		scanf("%s", inp);
		n = strlen(inp);
		sort(inp, inp + n, cmp);
		printf("%s\n", inp);
		while (next_permutation(inp, inp + n, cmp))
		{
			printf("%s\n", inp);
		}
	}
	return 0;
}
