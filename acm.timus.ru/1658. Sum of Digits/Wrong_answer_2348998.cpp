#include <iostream>
#include <algorithm>

using namespace std;

typedef int *INT_P;
typedef char *CHAR_P;

INT_P len[5010];
CHAR_P ans[5010];

void init(void)
{
	for (int i = 0; i <= 5005; ++i)
	{
		len[i] = (int *)(malloc(sizeof(int) * (5010 - i)));//new int [5010 - i];
		ans[i] = (char *)(malloc(sizeof(char) * (5010 - i)));//new char [5010 - i];
		memset(len[i], 34, sizeof(int) * (5010 - i));
		memset(ans[i], 0, sizeof(char) * (5010 - i));
	}
}


int &getlen(const int s1, const int s2)
{
	return len[s1][(s2 + s2 - s1) / 2];
}
char &getans(const int s1, const int s2)
{
	return ans[s1][(s2 + s2 - s1) / 2];
}

char calc(const int s1, const int s2)
{
	if (s2 + s2 < s1)
	{
		return '1';
	}
	if (getans(s1, s2) == 0)
	{
		if (s1 == 0)
		{
			return '*';
		}
		int p = 1;
		calc(s1 - 1, s2);
		int m = getlen(s1 - 1, s2);
		for (int i = 2; i < 10; ++i)
		{
			int ns1 = s1 - i;
			int ns2 = s2 - (i * i - i) / 2;
			if ((ns1 < 0) || (ns2 < 0)) break;
			if (calc(ns1, ns2) == '*') continue;
			if (m > getlen(ns1, ns2))
			{
				m = getlen(ns1, ns2);
				p = i;
			}
		}
		if (m < 100000)
		{
			getlen(s1, s2) = m + 1;
			getans(s1, s2) = '0' + p;
		}
		else
		{
			getans(s1, s2) = '*';
		}
	}
	return getans(s1, s2);
}

int main()
{
	int n;
	scanf("%d", &n);
	init();
	ans[0][0] = '@';
	len[0][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int s1, s2;
		scanf("%d%d", &s1, &s2);
		if ((s2 < s1) || (((s2 - s1) % 2) == 1))
		{
			printf("No solution\n");
			continue;
		}
		s2 -= s1; 
		s2 /= 2;
		if (calc(s1, s2) == '*')
		{
			printf("No solution\n");
			continue;
		}
		while (s1 != 0)
		{
			printf("%c", calc(s1, s2));
			int d = calc(s1, s2) - '0';
			int ns1 = s1 - d;
			int ns2 = s2 - (d * d - d) / 2;
			s1 = ns1;
			s2 = ns2;
		}
		printf("\n");
	}
	return 0;
}
