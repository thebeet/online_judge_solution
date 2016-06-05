#include <stdio.h>
#include <string.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
	int i, j, l1, l2, t, ans;
	char inp1[512], inp2[512], tmp[512];
	memset(inp1, 0, 512);
	memset(inp2, 0, 512);
	memset(tmp, 0, 512);
	
	scanf("%s", inp1);
	l1 = strlen(inp1);
	scanf("%s", inp2 + l1);
	l2 = strlen(inp2 + l1);
	if (l2 > l1)
	{
		strcpy(tmp, inp1);
		strcpy(inp1, inp2 + l1);
		memset(inp2, 0, 512);
		strcpy(inp2 + l2, tmp);
		t = l1;
		l1 = l2;
		l2 = t;
	}
	ans = 1000000;
	for (i = -l1; i < l2; ++i)
	{
		for (j = 0; j < l1; ++j)
		{
			if ((inp1[j] == '2') && (inp2[j + i + l1] == '2'))
			{
				break;
			}
		}
		if (j == l1)
		{
			ans = MIN(ans, MAX(MAX(l2 - i, i + l1), l1));
		}
	}
	printf("%d\n", ans);
	return 0;
}
