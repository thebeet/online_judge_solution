#include <iostream>

using namespace std;

bool alp[256];
int n;
int l;

bool isvowels(char ch)
{
	switch (ch)
	{
	case 'e':
	case 'a':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}

void dfs(int h, char p, int a, int b, string &out)
{
	if (h == l)
	{
		if ((a >= 2) && (b >= 1))
		{
			cout << out << endl;
		}
	}
	else
	{
		for ( ; p <= 'z'; ++p)
		{
			if (alp[(int)p])
			{
				out[h] = p;
				if (isvowels(p))
				{
					dfs(h + 1, p + 1, a, b + 1, out);
				}
				else
				{
					dfs(h + 1, p + 1, a + 1, b, out);
				}
			}
		}
	}
}

int main()
{
	int i;
	cin >> l >> n;
	memset(alp, false, sizeof(alp));
	for (i = 1; i <= n; ++i)
	{
		string inp;
		cin >> inp;
		alp[(int)inp[0]] = true;
	}
	string out(n, ' ');
	dfs(0, 'a', 0, 0, out);
	return 0;
}
