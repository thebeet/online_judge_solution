#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int prime[65536];
bool calc[65536];
int ansa[65536];
int ansb[65536];
int sqr[65536];

struct out
{
	int a, b;
}outs[100];
int outn;

bool cmp(const out &o1, const out &o2)
{
	if (o1.a == o2.a)
	{
		return (o1.b < o2.b);
	}
	else
	{
		return (o1.a < o2.a);
	}
}

int main()
{
	int i, j;
	memset(prime, 0, sizeof(prime));
	memset(calc, false, sizeof(calc));
	memset(sqr, 0, sizeof(sqr));
	sqr[1] = 1;
	for (i = 2; i <= 46340; ++i)
	{
		sqr[i] = i * i;
		if (prime[i] == 0)
		{
			prime[++prime[0]] = i;
			j = i * i;
			while (j <= 46340)
			{
				prime[j] = 1;
				j += i;
			}
		}
	}
	
	int ti, n;
	ti = 0;
	
	while (cin >> n)
	{
		cout << "Case #" << ++ti << ":";
		if (n == 1)
		{
			n = (n / (n - n));
		}
		outn = 0;
		for (i = 1; (i <= prime[0]) && (n > 1); ++i)
		{
			if ((n % prime[i]) == 0)
			{
				while ((n % prime[i]) == 0)
				{
					n /= prime[i];
				}
				if (calc[i] == false)
				{
					int ret;
					for (j = 1; sqr[j] <= prime[i]; ++j)
					{
						ret = (int)(sqrt((double)(prime[i] - sqr[j])) + 0.00000001);
						if (sqr[ret] + sqr[j] == prime[i])
						{
							break;
						}
					}
					if (sqr[j] <= prime[i])
					{
						ansa[i] = j;
						ansb[i] = ret;
					}
					else
					{
						ansa[i] = prime[i];
						ansb[i] = 0;
					}
					calc[i] = true;
				}
				outs[++outn].a = ansa[i];
				outs[outn].b = ansb[i];
			}
		}
		if (n > 1)
		{
			int ret;
			for (j = 1; sqr[j] <= n; ++j)
			{
				ret = (int)(sqrt((double)(n - sqr[j])) + 0.00000001);
				if (sqr[ret] + sqr[j] == n)
				{
					break;
				}
			}
			if (sqr[j] <= n)
			{
				outs[++outn].a = sqr[j];
				outs[outn].b = ret;
			}
		}
		sort(outs + 1, outs + 1 + outn, cmp);
		for (i = 1; i <= outn; ++i)
		{
			if (outs[i].b > 0)
			{
				cout << " " << outs[i].a;
				cout << "+";
				if (outs[i].b > 1)
				{
					cout << outs[i].b;
				}
				cout << "j,";
				
				cout << " " << outs[i].a;
				cout << "-";
				if (outs[i].b > 1)
				{
					cout << outs[i].b;
				}
				cout << "j";
			}
			else
			{
				cout << " " << outs[i].a;
			}
			if (i == outn)
			{
				cout << "\n";
			}
			else
			{
				cout << ",";
			}
		}
	}
	return 0;
}
