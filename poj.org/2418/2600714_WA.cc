#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1000010;

struct word
{
	char str[32];
}words[MAXN];

bool operator < (const word &w1, const word &w2)
{
	return (strcmp(w1.str, w2.str) == -1);
}

int main()
{
	int n = 0;
	freopen("inp", "r", stdin);
	while (gets(words[++n].str))
	{
	}
	sort(words + 1, words + n);
	words[n].str[0] = 255;
	int sum = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (words[i - 1] < words[i])
		{
			printf("%s %.4lf\n", words[i - 1].str, 100.0 * sum / (n - 1));
			sum = 1;
		}
		else
		{
			++sum;
		}
	}
	return 0;
}
