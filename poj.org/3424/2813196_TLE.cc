#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int x[128];
int y[128];

vector<string> ans;
typedef vector<string>::iterator iter;

string tans, tans2; 

int main()
{
	int i, j, g, dx, dy, n, xmin, ymin, xmax, ymax;
	cin >> n;
	xmin = ymin = 1024;
	xmax = ymax = -1;
	for (i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
		xmin = min(xmin, x[i]);
		ymin = min(ymin, y[i]);
		xmax = max(xmax, x[i]);
		ymax = max(ymax, y[i]);
	}
	if (((xmax - xmin) >= 300) || ((ymax - ymin) >= 300))
	{
		cout << "NONE" << endl;
		return 0;
	}
	int xst = xmin - 99;
	int yst = ymin - 99;
/*	if (xst < 0)
	{
		xst = 0;
	}
	if (yst < 0)
	{
		yst = 0;
	}*/
	for (i = xst; i <= xmin; ++i)
	{
		for (j = yst; j <= ymin; ++j)
		{
			int mxx = 0;
			int myy = 0;
			tans = string(n, '1');
			for (g = 0; g < n; ++g)
			{
				int yy = ((y[g] - j) / 100);
				int xx = ((x[g] - i) / 100);
				if ((yy >= 3) || (xx >= 3))
				{
					break;
				}
				mxx = max(mxx, xx);
				myy = max(myy, yy);
				
				tans[g] += (2 - yy) * 3 + xx;
			}
			if (g == n)
			{
				//cout << tans << endl;
				ans.push_back(tans);
				for (dx = 0; dx <= 2 - mxx; ++dx)
				{
					for (dy = 0; dy <= 2 - myy; ++dy)
					{
						if ((dx == 0) && (dy == 0))
						{
							continue;
						}
						string tans2(tans);
						for (g = 0; g < n; ++g)
						{
							tans2[g] += dx - dy * 3;
						}
						ans.push_back(tans2);
					}
				}
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << *ans.begin() << endl;
	
	for (iter i = ans.begin() + 1; i != ans.end(); ++i)
	{
		if (*i != *(i - 1))
		{
			cout << *i << endl;
		}
	}

	return 0;
}
