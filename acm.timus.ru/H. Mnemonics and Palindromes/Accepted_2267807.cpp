#include <iostream>

#define Max 4005
#define INF 0x7ffffff

using namespace std;

char s[Max];
int dp[Max];
bool rel[Max][Max];
int ans[Max];
int l;

void output(int n)
{
	if (n == 0)
	{
		return;
	}
	output(ans[n]-1);
	for (int i = ans[n]; i <= n; ++i)
	{
		printf("%c", s[i]);
	}
	if (n == l)
	{
		//printf("\n");
	}
	else
	{
		printf(" ");
	}
}

int main()
{
	while (gets(s+1) != NULL)
	{
		s[0] = ' ';
		l = strlen(s);
		--l;
		memset(rel, false, sizeof(rel));
		for (int i = 1; i <= l+1; ++i)
		{
			rel[i][i] = true;
			rel[i][i-1] = true;
		}
		for (int i = 2; i <= l; ++i)
		{
			for (int j = 1; j <= l-i+1; ++j)
			{
				int k = j+i-1;
				if (s[j] == s[k] && rel[j+1][k-1])
				{
					rel[j][k] = true;
				}
			}
		}
		fill(dp, dp+Max, INF);
		dp[0] = 0;
		for (int i = 1; i <= l; ++i)
		{
			for (int j = i; j >= 1; --j)
			{
				if (rel[j][i])
				{
					if (dp[i] > dp[j-1] + 1)
					{
						dp[i] = dp[j-1] + 1;
						ans[i] = j;
					}
				}
			}
		}
		printf("%d\n", dp[l]);
		output(l);
		getchar();
	}
	return 0;
}


		
				
			
