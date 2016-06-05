#include <iostream>

using namespace std;

int main()
{
	int wide;
	while ((cin >> wide), wide > 0)
	{
		int n, m;
		int hei, wid, nowhei, nowwid;
		
		hei = nowhei = 0;
		wid = nowwid = 0;
		while ((cin >> n >> m), n > 0)
		{
			nowwid += n;
			if (nowwid > wide)
			{
				hei += nowhei;
				nowhei = m;
				nowwid = n;
			}
			else
			{
				nowhei = max(nowhei, m);
			}
			wid = max(wid, nowwid);
		}
		hei += nowhei;
		cout << wid << " x " << hei << endl;
	}
	return 0;
}
