#include <iostream>
#include <string>

using namespace std;

int main()
{
	string ct1, ct2, cls;
	while ((cin >> ct1), ct1 != "#")
	{
		int l;
		int ans = 0;
		while (ct1 != "0")
		{
			cin >> ct2 >> l >> cls;
			switch (cls[0])
			{
			case 'F':
				l = l << 1;
				break;
			case 'B':
				l = l + ((l + 1) >> 1);
				break;
			case 'Y':
				if (l < 500)
				{
					l = 500;
				}
			}
			ans += l;
			cin >> ct1;
		}
		cout << ans << endl;
	}
	return 0;
}
