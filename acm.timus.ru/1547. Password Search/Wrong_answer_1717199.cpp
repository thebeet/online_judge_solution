#include <stdio.h>
#include <memory.h>

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
		if (i == n)
		{
			d[i] = (ff * 26) / m;
			ff = (ff * 26) % m;
		}
		else
		{
			d[i] = (ff * 26 + 1) / m;
			ff = (ff * 26 + 1) % m;
		}
	}
	--d[n];
	for (j = n; d[j] < 0; --j)
	{
		d[j] = 25;
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
		for (j = 1; j <= n; j++)
		{
			if (s[j] == 0) continue;
			printf("%c", s[j] + 'a' - 1);
		}
		printf("-");
		
		if (i <= ff) 
		{
			++s[n];
		}
		for (j = n; j >= 1; --j)
		{
			s[j] += d[j];
			s[j - 1] += ((s[j] - 1) / 26);
			s[j] = (s[j] - 1) % 26 + 1;
		}
		for (j = 1; j <= n; j++)
		{
			if (s[j] == 0) continue;
			printf("%c", s[j] + 