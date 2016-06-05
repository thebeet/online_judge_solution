#include <iostream>

using namespace std;

int ans[32][32][32];
bool iscalc[32][32][32];

int calc(int a, int b, int c)
{
	if ((a <= 0) || (b <= 0) || (c <= 0))
	{
		return 1;
	}
	if ((a > 20) || (b > 20) || (c > 20))
	{
		a = b = c = 20;
	}
	if (iscalc[a][b][c] == false)
	{
		if ((a < b) && (b < c))
		{
			ans[a][b][c] = calc(a, b, c - 1)
				     + calc(a, b - 1, c - 1)
				     - calc(a, b - 1, c);
		}
		else
		{
			ans[a][b][c] = calc(a - 1, b, c)
				     + calc(a - 1, b - 1, c)
				     + calc(a - 1, b, c - 1)
				     - calc(a - 1, b - 1, c - 1);
		}
		iscalc[a][b][c]= true;
	}
	return ans[a][b][c];
}

int main()
{
	int a, b, c;
	while ((cin >> a >> b >> c), (a != -1) || (b != -1) || (c != -1))
	{
		printf("w(%d, %d, %d) = ", a, b ,c);
	       	cout << calc(a, b, c) << endl;
	}
	return 0;
}

