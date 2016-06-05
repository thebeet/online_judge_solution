#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int q, d, n, p, c, aq, ad, an, ap;
	while ((cin >> q >> d >> n >> p >> c), q + d + n + p + c > 0)
	{
		int aaq, aad, aan, aap;
		int mn = 100000;
		if (q > 3) q = 3;
		if (d > 9) d = 9;
		if (n > 19) n = 19;
		for (aq = 0; aq <= q; ++aq)
		{
			for (ad = 0; ad <= d; ++ad)
			{
				for (an = 0; an <= n; ++an)
				{
					if (((aq * 25 + ad * 10 + an * 5) <= c) && ((aq * 25 + ad * 10 + an * 5 + p) >= c))
					{
						ap = c - (aq * 25 + ad * 10 + an * 5);
						if ((aq + ad + an + ap) <= mn)
						{
							aaq = aq;
							aad = ad;
							aan = an;
							aap = ap; 
							mn = aq + ad + an + ap;
						}
					}
				}
			}
		}
		if (mn <= 1000)
		{
			printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies\n", aaq, aad, aan, aap);
		}
		else
		{
			cout << "Cannot dispense the desired amount." << endl;
		}
	}
	return 0;
}
