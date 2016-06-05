#include <cstdio>
#include <cstring>

char buf[2048];

int main()
{
	int i, ans;
	gets(buf);
	ans = 0;
	for (i = 0; i < strlen(buf); ++i)
	{
		if ((buf[i] >= 'a') && (buf[i] <= 'z'))
		{
			ans += ((buf[i] - 'a') % 3) + 1;
		}
		else if (buf[i] == '.')
		{
			ans += 1;
		}
		else if (buf[i] == ',')
		{
			ans += 2;
		}
		else if (buf[i] == '!')
		{
			ans += 3;
		}
		else if (buf[i] == ' ')
		{
			ans += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
