#include <stdio.h>
#include <memory.h>

void out(int s[], int n, char c)
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		if (s[i] == 0) continue;
		printf("%c", s[i] + 'a' - 1);
	}
	printf("%c", c);
	return;
}

int main()
{
	int i, j, n, m, ff;
	int d[55];
	int s[55];
	
	scanf("%d%d", &n, &m);

	memset(d, 0, sizeof(d));
	memset(s, 0, sizeof(s));

	ff = 1;
	for (i = 1; i <= n; i++)
	{
		d[i] = (ff * 26) / m;
		ff = (ff * 26) % m + 1;
	}
	--d[n];
	--ff;
	for (j = n; d[j] == 0; --j)
	{
		d[j] = 26;
		--d[j - 1];
	}
	for (i = 1; i <= m; i++)
	{
		++s[n];
		for (j = n; s[j] > 26; --j)
		{
			s[j] = 1;
			++s[j - 1];
		}
		out(s, n, '-');
		
		if (i <= ff) 
		{
			++s[n];
			for (j = n; s[j] > 26; --j)
			{
				s[j] = 1;
				++s[j - 1];
			}
		}
		for (j = n; j >= 1; --j)
		{
			s[j] += d[j];
			s[j - 1] += ((s[j] - 1) / 26);
			s[j] = (s[j] - 1) % 26 + 1;
		}
		out(s, n, '\n');
	}
	return 0;
}
