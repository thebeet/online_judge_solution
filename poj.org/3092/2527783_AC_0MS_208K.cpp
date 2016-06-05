#include <iostream>

using namespace std;

int ansx[128];
int ansy[128];

int binarysize(int n)
{
	int ans = 0;
	while (n >= (1 << ans))
	{
		++ans;
	}
	return ans - 1;
}

void calc(int n)
{
	int si;
	int p3 = 0;
	while (n > 0)
	{
		while ((n % 3) == 0)
		{
			n /= 3;
			++p3;
		}
		si = binarysize(n);
		if (((n - (1 << si)) % 3) == 0)
		{
			n -= (1 << si);
			ansx[++ansx[0]] = si;
			ansy[ansx[0]] = p3;
		}
		else
		{
			--si;
			n -= (1 << si);
			ansx[++ansx[0]] = si;
			ansy[ansx[0]] = p3;
		}
	}
}

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n;
		scanf("%d", &n);
		ansx[0] = 0;
		calc(n);
		cout << ti << " " << ansx[0] << " ";
		for (i = 1; i < ansx[0]; ++i)
		{
			cout << "[" << ansx[i] << "," << ansy[i] << "] "; 
		}
		cout << "[" << ansx[i] << "," << ansy[i] << "]" << endl; 
	}
	return 0;
}
