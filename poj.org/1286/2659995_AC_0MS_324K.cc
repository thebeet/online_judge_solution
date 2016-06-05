#include <iostream>

using namespace std;

long long pow3[32];
long long perm[32];
bool gone[32];
long long n;

template <typename T_INT>
T_INT gcd(T_INT a, T_INT b)
{
	T_INT r;
	if (b > a)
	{
		swap(a, b);
	}
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int calcperm()
{
	long long i, ans;
	memset(gone, false, sizeof(gone));
	ans = 0;
	
	for (i = 1; i <= n; ++i)
	{
		if (gone[i] == false)
		{
			++ans;
			int p = i;
			while (gone[p] == false)
			{
				gone[p] = true;
				p = perm[p];
			}
		}
	}
	
	return ans;
}

int main()
{
	long long i, j;
	pow3[0] = 1;
	for (i = 1; i <= 24; ++i)
	{
		pow3[i] = pow3[i - 1] * (long long)3;
	}
	while ((cin >> n), n >= 0)
	{
		long long ans = 0;
		if (n != 0)
		{
			for (i = 1; i <= n; ++i)
			{
				ans += pow3[gcd(i, n)];
				for (j = 1; j <= n; ++j)
				{
					perm[j] = i - j;
					if (perm[j] <= 0)
					{
						perm[j] += n;
					}
				}
				ans += pow3[calcperm()];
			}
			ans /= (long long)(n + n);
		}
		cout << ans << endl;
	}
	return 0;
}
