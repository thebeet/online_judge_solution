#include <iostream>
#include <cmath>

using namespace std;

struct t_Point
{
	double x, y, z;
};

double operator !(const t_Point &p1)
{
	return sqrt(p1.x * p1.x + p1.y * p1.y + p1.z * p1.z);
}

double operator *(const t_Point &p1, const t_Point &p2)
{
	return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

istream &operator >>(istream &in, t_Point &p)
{
	return (cin >> p.x >> p.y >> p.z);
}

t_Point star[512];
bool insight[512];
t_Point scope[512];
double phi[512];

int main()
{
	int i, j, n, m;
	while ((cin >> n), n > 0)
	{
		for (i = 1; i <= n; ++i)
		{
			cin >> star[i];
			insight[i] = false;
		}
		cin >> m;
		for (j = 1; j <= m; ++j)
		{
			cin >> scope[j];
			cin >> phi[j];
			for (i = 1; i <= n; ++i)
			{
			
				double ret = acos((scope[j] * star[i]) / (!scope[j] * !star[i]));
				if (ret - 0.000000001 <= phi[j])
				{
					insight[i] = true;
				}
			}
		}
		int ans = 0;
		for (i = 1; i <= n; ++i)
		{
			if (insight[i])
			{
				++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
