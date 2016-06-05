#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char inp[500];
char orginp[500];
int var[500]; 
bool use[500];

int main()
{
	int ti, tn;
	char inpch;
	cin >> tn;
	while (scanf("%c", &inpch), inpch != '\n')
	{
	}
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, ans, st, n, sign;
		n = 0;
		ans = 0;
		memset(inp, 0, sizeof(inp));
		memset(var, 0, sizeof(var));
		memset(use, false, sizeof(use));
		for (char ch = 'a'; ch <= 'z'; ++ch)
		{
			var[(unsigned int)ch] = ch - 'a' + 1;
		}
		gets(orginp);
		for (i = 0; i < strlen(orginp); ++i)
		{
			inpch = orginp[i];
			if (((inpch >= 'a') && (inpch <= 'z')) || (inpch == '-') || (inpch == '+'))
			{
				inp[++n] = inpch;
			}
		}
		if ((inp[1] != '+') && (inp[1] != '-'))
		{
			inp[0] = '+';
			st = 0;
		}
		else
		{
			st = 1;
		}
		for (i = st; i <= n; ++i)
		{
			if (inp[i] == '+')
			{
				sign = 1;
			}
			else
			{
				sign = -1;
			}
			++i;
			if ((inp[i] == '+') && (inp[i + 1] == '+'))
			{
				i += 2;
				++var[(unsigned int)inp[i]];
				ans += sign * var[(unsigned int)inp[i]];
				use[(unsigned int)inp[i]] = true;
			}
			else if ((inp[i] == '-') && (inp[i + 1] == '-'))
			{
				i += 2;
				--var[(unsigned int)inp[i]];
				ans += sign * var[(unsigned int)inp[i]];
				use[(unsigned int)inp[i]] = true;
			}
			else
			{
				use[(unsigned int)inp[i]] = true;
				ans += sign * var[(unsigned int)inp[i]];
				if ((inp[i + 1] == '-') && (inp[i + 2] == '-'))
				{
					--var[(unsigned int)inp[i]];
					i += 2;
				}
				else if ((inp[i + 1] == '+') && (inp[i + 2] == '+'))
				{
					++var[(unsigned int)inp[i]];
					i += 2;
				}
			}
		}
		cout << "Expression: " << orginp << endl;
		cout << "value = " << ans << endl;
		for (char ch = 'a'; ch <= 'z'; ++ch)
		{
			if (use[(unsigned int)ch])
			{
				cout << ch << " = " << var[(unsigned int)ch] << endl;
			}
		}
	}
	return 0;
}
